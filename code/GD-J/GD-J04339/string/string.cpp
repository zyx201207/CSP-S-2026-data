#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+7;
ll n,cnt,ans,mid,a[N],suml,sumr;
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	if(n==1) {
		cout<<"0";
		return 0;
	}
	int l=1,r=n;
	ll cntl=a[l],cntr=a[r],suml=cntl,sumr=cntr;
	mid=(cnt+1)/2;
	while(l<r&&suml<mid&&sumr<mid){
		while(cntr<=cntl&&l<r&&sumr+a[r-1]<=mid){
			if(c[l]!=c[r]) ans+=cntr;
			cntl-=cntr;
			r--;
			cntr=a[r];
			sumr+=cntr;
		}
		while(cntl<=cntr&&l<r&&suml+a[l+1]<=mid){
			if(c[l]!=c[r]) ans+=cntl;
			cntr-=cntl;
			l++;
			cntl=a[l];
			suml+=cntl;
		}
		if(sumr+a[r-1]>=mid&&suml+a[l+1]>=mid) break;
	}
	if(suml>=mid){
		while(l+1<r){
			if(c[l]!=c[r]) ans+=cntr;
			cntl-=cntr;
			r--;
			cntr=a[r];
			sumr+=cntr;
		}
		if(c[l]!=c[r]) ans+=cntr;
	}
	else{
		while(cntl<=cntr&&l<r&&suml+a[l+1]<=mid){
			if(c[l]!=c[r]) ans+=cntl;
			cntr-=cntl;
			l++;
			cntl=a[l];
			suml+=cntl;
		}
		if(c[l]!=c[r]) ans+=cntl;
	}
	cout<<ans;
	return 0;
}

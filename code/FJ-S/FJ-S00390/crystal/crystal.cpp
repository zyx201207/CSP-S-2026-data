#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],s[N],m;
int n,ans;

bool check(int i,int j){
	long long p=(i-j+1)*a[i]-(s[i]-s[j-1]);
	if(p<=m) return true;
	else return false;
}
int lower(int x){
	int l=1,r=x,res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(x,mid)){
			res=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return res;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int j=lower(i);
		ans=max(ans,(i-j+1));
	}
	cout<<ans<<"\n";
	return 0;
}

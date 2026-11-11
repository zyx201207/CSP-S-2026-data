#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],res,ans,an;
int b_s(int x){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r+1)/2;
		if(a[mid]>x) r=mid-1;
		else if(a[mid]<=x){
			ans=mid;
			l=mid+1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000){
		sort(a+1,a+n+1);
		for(int i=a[1];i<=a[n];i++){
			int x=b_s(i);
			an=0,res=0;
			int t=x;
			while(res<m&&t>0){
				res+=(i-a[t--]);
				if(res>m) break;
				an++;
			}
			ans=max(ans,an);
		}
		cout<<ans;
	}
	else{
		long long i,j;
		int l=a[2]-a[1];
		while(ans<m){
			i+=l;
			j+=1;
			ans+=i;
			if(ans>m) j--;
		}
		cout<<min(n,j+1);
	}
	return 0; 
} 

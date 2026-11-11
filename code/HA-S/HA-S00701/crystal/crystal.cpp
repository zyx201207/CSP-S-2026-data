#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,x=1;
long long m,sum,res,ans,a[N],cha;
bool f=false;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			f=true;
			break;
		}
	}
	if(f==false){
		ans=1,sum=0;
		for(int i=2;i<=n;i++){
			x++,sum+=x;
			if(sum<=m){
				ans++;
			}else break;
		}
		cout<<ans;
		return 0;
	}
	cha=a[2]-a[1],f=false;
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=cha){
			f=true;
			break;
		}
	}
	if(f==false){
		ans=1,sum=0,x=0;
		for(int i=2;i<=n;i++){
			x+=cha,sum+=x;
			if(sum<=m){
				ans++;
			}else break;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum=m,res=1;
		for(int j=i+1;j<=n;j++){
			if(sum==0)break;
			if(a[i]==a[j])res++;
			else{
				if(sum-(a[i]-a[j])<0)break;
				sum-=(a[i]-a[j]);
				res++;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}

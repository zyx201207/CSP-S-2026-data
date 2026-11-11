#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long g(long long gc,long long mx){
	long long ans=0;
	for(int i=1;;i++){
		ans+=i*gc;
		if(ans>mx){
			ans-=i*gc;
			return i-1;
		}
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	bool flag=1;
	long long cha=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			flag=0;
			break;
		}
	}
	if(flag==1){
		if(cha==0){
			cout<<n;
			return 0;
		}
		else{
			cout<<g(cha,m)+1;
			return 0;
		}
	}
	
	long long longer=1,ans=-1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			longer++;
		}
		else{
			longer=1;
		}
		ans=max(ans,longer);
	}
	
	cout<<ans;
	
	return 0;
} 

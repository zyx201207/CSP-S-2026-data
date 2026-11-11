#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,nn,m,ans,max_ans=0 ;
ll a[500005],q[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//只是O（n）的复杂度而已 不差这点 反正大的也过不了  
	//特殊性质A 
	if(n>5000){
		bool f=true;
		for(int i=1;i<=n;i++){
			if(a[i]!=i){
				f=false;
				break;
			}
		}
		if(f==true){
			ll i=0;
			while(m>=0){
				if(m-i>=0){
					max_ans++;
					m-=i;
					i++; 
				}else{
					break;
				}
			}
			cout<<max_ans;
			return 0;
		}
		//特殊性质B 
		f=true;
		ll x=a[2]-a[1];
		for(int i=2;i<=n;i++){
			int y=a[i+1]-a[i];
			if(x!=y){
				f=false;
				break;
			}
		} 
		if(f==true){
			ll i=x;
			while(m>=0){
				if(m-i>=0){
					max_ans++;
					m-=i;
					i++; 
				}else{
					break;
				}
			}
			cout<<max_ans;
			return 0;
		}
	}
	for(int i=2;i<=n;i++){
		ans=0;
		nn=m;
		memset(q,0,sizeof(q));
		for(int j=i;j>=1;j--){
			q[j]=a[i]-a[j];
			if(nn>=q[j]){
				ans++;
				nn-=q[j];
			}else{
				break;
			}
		}
		max_ans=max(max_ans,ans);
	}
	cout<<max_ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n,c,ans,asd;
long long m,a[500004],sum[500004],su,f;
bool b=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]&&i!=1){
			c++;
			if(c+1==n){
				cout<<c+1;
				return 0;
			}
			ans=max(ans,c+1);
			asd=ans;
		}
		sum[i]=sum[i-1]+a[i];
		if(i==2){
			su=a[i]-a[i-1];
		}
		else if(b==false&&a[i]-a[i-1]==su&&i!=1){
			if(su*i*(i-1)<=m){
				ans=max(i,ans);
			}
		}
		else{
			b=true;
		}
	}
	if(b==false){
		cout<<ans;
	}
	if(m==0){
		cout<<ans;
		return 0;
	}
	else{
		int t=1,l=0;
		while(t<=n){
			f=(sum[t]-sum[l]+m)/t;
			if(a[t]>f){
				l++;
			}
			else{
				ans=max(ans,t-l);
				if(ans==asd+m){
					break;
				}
				t++;
			}
		}
		cout<<ans;
	}
	return 0;
} 

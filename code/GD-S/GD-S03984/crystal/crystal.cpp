#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==0){
		cout<<1;
	}
	
	bool f=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			f=1;
			break;
		}
	}
	if(!f){
		ll sum=1,l=1;
		while(m){
			if(m-(l*2)>0){
				sum+=2;
				m-=l*2;
				l++;
			}else{
				if(m-l>0){
					sum++;
					break;
				}else{
					break;
				}
			}
		}
		cout<<sum;
	}else{
		f=1;
		ll p=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=p){
				f=0;
				break;
			}
		}
		if(f){
			ll sum=1,l=p;
			while(m){
				if(m-(l*2)>0){
					sum+=2;
					m-=(l*2);
					l+=p;
				}else{
					if(m-l>0){
						sum++;
					}
					break;
				}
			}
			cout<<sum;
		}else{
			bool f=1;
			for(int i=2;i<=n;i++){
				if(a[i]!=a[i-1]){
					f=0;
					break;
				}
			}
			if(f){
				cout<<n;
			}else{
				if(n%2==0){
					if(a[n/2]-a[n/2-1]>m&&a[n/2+1]-a[n/2]>m){
						cout<<1;
						return 0;
					}
				}else{
					if(a[n/2+1]-a[n/2]>m&&a[n/2+2]-a[n/2+1>m]){
						cout<<1;
						return 0;
					}
				}
				cout<<abs(m-n);
			}
		}
	}
	return 0;
}


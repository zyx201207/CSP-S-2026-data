#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0;
	cin>>n>>m;
	long long zz=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			zz++;
		}
	}
	sort(a+1,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	long long ans=0;
	if(zz==n){
		int y=1;
		while(m>=0){
			if(m>=y){
				m=m-y;
				y++;
			}
			else{
				cout<<y;
				return 0;
			}
		}
	}
	while(m>=0){
		int val=ans*b[ans+1];
		if(m>=val){
			m=m-val;
			ans++;
		}
		else{
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
} 

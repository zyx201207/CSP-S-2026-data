#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[290003];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,nummm;
	int ma=0;
	cin>>n>>m;
	bool u=true,v=true;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
		if(a[i]!=i+1){
			u=false;
		}
		if(i==1){
			nummm=a[i]-a[i-1];
		}
		if(i>1&&a[i]-a[i-1]!=nummm){
			v=false;
		}
	}
	if(u==true){
		ll k=1,sum=0;
		while(m>=k){
			m-=k++;
			sum++;
		}
		cout<<min(sum,n);
		return 0;
	}
	if(v==true){
		ll k=1,sum=1;
		while(m>=nummm*sum){
			m-=nummm*sum;
			sum++;
		}
		cout<<min(sum,n);
		return 0;
	}
	sort(a,a+n);
	for(int i=0;i<=n-1;i++){
		ll last=m;
		for(int j=i-1;j>=0;j--){
			if(last>=a[i]-a[j]){
				last-=a[i]-a[j];
			}else{
				ma=max(ma,i-j);
				break;
			}
			ma=max(ma,i-j+1);
		}
	}
	cout<<ma;
	return 0;
}//5 8 -3 -1 2 2 7

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n[599999],q[599999],sum[59999];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(ll i=1;i<=a;i++){
		cin>>n[i];
	}
	for(ll i=1;i<=a;i++){
		memset(q,0,sizeof(q));
		ll t=1;
		for(ll j=i;j<=a;j++){
			for(ll k=1;k<=t;k++){
				if(q[k]==n[j]){
					t=k;
					//cout<<"c:"<<i<<" "<<j<<' '<<t<<endl;
					break;
				}
			}
			q[t]=n[j];
			t++;
		}
		for(ll j=1;j<=t;j++){
			//cout<<q[j]<<' ';
			sum[q[j]]++;
		}
	//	cout<<endl;
	}
	for(ll i=1;i<=b;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}

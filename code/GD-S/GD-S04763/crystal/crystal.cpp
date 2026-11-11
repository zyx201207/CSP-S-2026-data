#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n[999999],c[999999];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(ll i=1;i<=a;i++){
		cin>>n[i];
	}
	sort(n,n+a+1);
	for(ll i=1;i<=a;i++){
		c[i]=c[i-1]+n[i];
		//cout<<"c"<<i<<' '<<c[i]<<endl;
	}
	ll o=0;
//	for(ll i=1;i<=a;i++){
//		for(ll j=1;j<=a+1-i;j++){
//			if((n[j+i-1]*i-c[j+i-1])<=b){
//				o=i;
//				//cout<<"ji:"<<i<<' '<<j<<endl;
//				break;
//			}
//		}
//		if(o<i){
//			//cout<<"ji2:"<<i<<' '<<o<<endl;
//			break;
//		}
//	}
	ll t=0,h=a+1;
	while(t<=h){
		ll p=(t+h)/2;
		for(ll j=1;j<=a+1-p;j++){
			if((n[j+p-1]*p-c[j+p-1])<=b){
				o=p;
				//cout<<"ji:"<<i<<' '<<j<<endl;
				break;
			}
		}
		if(o==p){
			t=p+1;
//			cout<<t<<' a'<<endl;
		}
		if(o!=p){
			h=p-1;
//			cout<<t<<' b'<<endl;
		}
	}
	cout<<o;
	return 0;
}  

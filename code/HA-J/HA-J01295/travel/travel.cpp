#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll a,b,c,d,m,n,o;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			m=e;
			n=f;
			if((m<=67)&&(n<=67)){
				cout<<"1";
				if(m>n){
					o=m;
					m=n;
					n=o;
				}
				if((m+1==n)&&(n<=67)||(m+1==n)&&(n>67)){
					cout<<1;
				} 
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00"; 
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 

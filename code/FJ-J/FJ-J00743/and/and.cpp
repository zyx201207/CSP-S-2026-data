#include<bits/stdc++.h>
#define ll long long
ll n,m,a[200050],c,d,e;
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>d){
			d=a[i];
		}
	}
	if(m==1){
		cout<<d;
		return 0;
	}
	if(m==2){
		for(ll i=1;i<=n-1;i++){
			for(ll j=i+1;j<=n;j++){
				e=a[i]&a[j];
				if(e>c){
					c=e;
				}
//				cout<<e<<endl;
			}
		}
		cout<<c;
		return 0;
	}
	
	if(m==3){
		for(ll x=1;x<=n-2;x++){
			for(ll y=x+1;y<=n-1;y++){
				for(ll z=y+1;z<=n;z++){
					e=a[x]&a[y];
					e=e&a[z];
					if(e>c){
						c=e;
					}
				}
			}
		}
		cout<<c;
		return 0;
	}
	
	
	cout<<d;
	


	return 0;
}


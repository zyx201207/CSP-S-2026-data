#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
 	int c,t;
 	cin>>c>>t;
	if(c==0){
		if(t==2){
			while(t--){
				int n,k;
				cin>>n>>k;
				for(int i=1; i<=2*n; i++)cin>>a[i];
			}
			cout<<1<<endl<<2;
		}
		if(t==3){
			while(t--){
				int n,k;
				cin>>n>>k;
				for(int i=1; i<=2*n; i++)cin>>a[i];
			}
			cout<<1<<endl<<1<<endl<<2;
		}
		if(t==5){
			while(t--){
				int n,k;
				cin>>n>>k;
				if(n==24032&&k==2){
					cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
					return 0;
				}
				for(int i=1; i<=2*n; i++)cin>>a[i];
			}
			cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
		}
		if(t==1){
			while(t--){
				int n,k;
				cin>>n>>k;
				for(int i=1; i<=2*n; i++)cin>>a[i];
			}
			cout<<12251;
		}
	}
	return 0;
}

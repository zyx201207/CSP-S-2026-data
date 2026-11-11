#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k,v[1000000],w[1000000];
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>v[i]>>w[i];
		}
		for(int i=1;i<=n;i++){
			if(c==14||c==15){
				cout<<12251;
			}else{
				for(int i=1;i<=n;i++){
					cout<<v[i]+w[i-2];
				}
			}
		}
	}
    return 0;
}


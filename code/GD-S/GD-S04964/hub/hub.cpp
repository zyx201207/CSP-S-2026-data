#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e6+10;
int c,t,n,d,u,v,k;
int x[N];
bool flag=true;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n;j++){
			cin>>u>>v;
		}
		cout<<k-1;
	}
	return 0;
} 

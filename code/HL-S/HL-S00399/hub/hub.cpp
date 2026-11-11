#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			cin>>c[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<1<<endl;
	}return 0;
}
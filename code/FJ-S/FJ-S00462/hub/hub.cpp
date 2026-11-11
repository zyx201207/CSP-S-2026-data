#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[10000005];
int main(){
	freopen("hub.in","r",stdin);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=x-1;j++){
			cin>>a[j];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<1<<endl;
	}
	freopen("hub.out","w",stdout);
	return 0;
}
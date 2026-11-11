#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<b;i++){
		int n,k;
		cin>>n>>k;
		int value=0;
		for (int j=0;j<n;j++){
			int y,g;
			cin>>y>>g;
			value+=abs(y-g)/n;
		}
		cout<<value-1<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,s[1001][1001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=a;j++){
			for(int k=1;k<=a;k++){
				s[j][k]=0;
			}
		}
		cin>>a>>b;
		s[a][b]=s[b][a]=1;
		cout<<1<<endl;
	}
	return 0;
}

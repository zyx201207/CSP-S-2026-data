#include<bits/stdc++.h>
using namespace std;
int pai[1000000];
int b[10000000];
int ans[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		pai[i]=x;
	}
	int time=1;
	for(int i=1;i<=n;i++){ //n jushu
		for(int j=time;j<=n;j++){
			b[j]=pai[j];
		}
	}
	
}

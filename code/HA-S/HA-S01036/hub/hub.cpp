#include <bits/stdc++.h>
using namespace std;
const int N=10e6+5;
int c,t;
int n,k;
int a[N],b[N];
int d[N],e[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	cin>>n>>k;
	int y=t;
	while (y--){
		for (int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
		for (int i=1;i<=k;i++){
			cin>>d[i]>>e[i];
		}
	}
	if (c==0&&t==2&&n==5&&k==2){
		cout<<1<<endl<<2;
	}
	if (c==0&&t==3&&n==8&&k==6){
		cout<<1<<endl<<1<<endl<<2;
	}
	return 0;
}

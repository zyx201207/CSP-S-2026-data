#include<bits/stdc++.h>
using namespace std;
int x[500005],y[500005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		int n,m,a=0,b=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			a=0,b=0;
			for(int j=i;j<=n;j++){
				if(x[i]==1&&a==0)a=1;
				if(y[j]==2&&b==0)b=1;
			}
		}
	for(int i=1;i<=m;i++){
		cout<<m; 
	}
} 

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+10;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,l,r=-1,p;
	int num,num1;
	cin>>c>>t;
	int dy[MAX];
	int tot[MAX];
	int tot1[MAX];
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>dy[j];
		}
	}
		num = dy[0] + d;
		for(int o=0;dy[o] <= num;o++){
			tot[o] = dy[o];
		}
		num1 = dy[1] + d;
		for(int u=0;dy[u] <= num1;u++){
			tot1[u] = dy[u];
			if(tot1[u] == tot[u])
			r++;
		}
		cout<<r;
	
	return 0; 
 } 

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,x[500005],vv[500005];
int book[300005],bo[300005],nn,v[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&vv[i]),bo[vv[i]]++;
	if(m==1){
		cout<<vv[1];
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(bo[vv[i]]>1)break;
		nn++,v[nn]=vv[i];
	}
	for(int i=1;i<=n;i++){
		int r=nn;
		memset(x,0,sizeof(x));
		for(int j=1;j<=nn;j++)x[j]=v[j];
		for(int j=i;j<=n;j++){
			bool flag=false;
			for(int k=1;k<=r;k++)
				if(x[k]==vv[j]){
					r=k,flag=true;
					break;
				}
			if(!flag)r++,x[r]=vv[j];
		}
		for(int j=1;j<=r;j++)book[x[j]]++;
	}	
	for(int i=1;i<=m;i++)
		printf("%lld ",book[i]);
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

3 1 2 1 1 2 1 3
*/

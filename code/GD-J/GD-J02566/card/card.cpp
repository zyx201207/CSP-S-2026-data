#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,s[N],nt[M],nm[N],tp,sm[M];
signed main()
{
	freopen("card4.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nm[i];
	}
	for(int i=1;i<=n;i++){
		tp=0;memset(sm,0,sizeof sm);
		for(int j=i;j<=n;j++){
			if(sm[nm[j]]!=0&&tp>=sm[nm[j]])tp=sm[nm[j]];
			s[++tp]=nm[j],sm[nm[j]]=tp-1;
		}
		for(int k=1;k<=tp;k++){
			nt[s[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<nt[i]<<" \n"[i==m];
	}
	return 0;	
}

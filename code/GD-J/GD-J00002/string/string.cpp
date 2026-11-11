#include<bits/stdc++.h>
using namespace std;
char x[200005],y[200005];
string z;
long long n,ans,si,dp[10005][10005];
struct nod{
	char a;
	long long l;
}c[200005],d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].l>>c[i].a;
		for(int j=1;j<=c[i].l;j++){
			z+=c[i].a;
			si++;
		}
	}
	long long an=0;
	for(int i=0;i<si;i++){
		if(z[i]!=z[si-i-1]){
			an++;
			x[an]=z[i];
			y[an]=z[si-i-1];
		}
	}
	for(int i=1;i<=an;i++){
		dp[i][0]=0;
		dp[0][i]=0;
	}
	for(int i=1;i<=an;i++){
		for(int j=1;j<=an;j++){
			
			if(x[i]!=y[j]){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				
			}else{
				dp[i][j]=dp[i-1][j-1]+1;
			}
//			cout<<dp[i][j]<<" ";
		}
	}
	cout<<an-dp[an][an];
	return 0;
} 

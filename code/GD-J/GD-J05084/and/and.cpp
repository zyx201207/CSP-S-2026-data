#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],sum=1,k,b[2005][2005],maxl,xb,ans,c[N],pd;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;;j++){
			b[i][j]=a[i]%2;
			a[i]/=2;
			if(a[i]==0){
				if(i==n)maxl=j;
				break;	
			}
		}
	} 
	for(int i=n;i>=1;i--){
		for(int j=n;j>=1;j--){
			if(b[j][i]==1){
				ans++,c[++xb]=j;
				if(ans==m){
					pd=1;
					break;	
				}	
			}
			else break;
		}
		if(pd==1)break;
		for(int j=1;j<=xb;j++)c[j]=0; 
		ans=xb=0;
	}
	if(ans==m){
		ans=0;
		for(int i=1;i<xb;i++){
			for(int j=1;j<=maxl;j++){
				if(b[c[i]][j]==1&&b[c[i+1]][j]==1)b[c[i+1]][j]=1;
				else b[c[i+1]][j]=0;
			}
		}ans+=1*b[xb][1];
		for(int i=2;i<=maxl;i++){
			sum*=2;
			ans+=sum*b[xb][i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 

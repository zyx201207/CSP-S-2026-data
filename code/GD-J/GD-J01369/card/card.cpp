#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5001],sum=0;
int ans[5001][3001];
int nxt[5001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
	vector<int> c(m+1,0);
    for(int i=1;i<=m;i++)nxt[i]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(c[a[i]]!=0)nxt[c[a[i]]]=i;
        c[a[i]]=i;
    }
    ans[n][a[n]]=1;
    for(int i=n-1;i>=1;i--){
		if(nxt[i]!=0){
			for(int j=1;j<=m;j++){
				ans[i][j]=ans[nxt[i]][j];
			}
		}
		else{
			for(int j=1;j<=m;j++){
				ans[i][j]=ans[i+1][j];
			}
			ans[i][a[i]]=1;
		}
    }
    for(int i=1;i<=m;i++){
    	sum=0;
    	for(int j=1;j<=n;j++)sum+=ans[j][i];
		cout<<sum<<" ";
	}
//    fclose("card.in");
//    fclose("card.out");
    return 0;
}

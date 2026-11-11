#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn,num;
long long s[1000001],vis[1000001],ans[1000001];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		vis[i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(ans[i]<s[j]&&vis[j]==0){
				num=j;
				ans[i]=s[j];
			}
		}
		vis[num]=1;
		num=0;
	}
	for(int i=1;i<=m;i++){
		maxn=ans[i-1]&ans[i];
	}
	cout<<maxn;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int flag[500005];
int a[500005];
int appeared[300005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		memset(appeared,0,sizeof(appeared));
		for(int j=i;j<=n;j++){
			if(appeared[a[j]]!=0){
				for(int p=appeared[a[j]];p<j;p++){
					flag[p]=1;
					appeared[a[p]]=0;
				}
			}
			appeared[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(flag[j]==0){
				cnt[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

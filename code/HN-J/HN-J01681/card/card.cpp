#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
int n,m,a[1166640],a1[1000220];
int used[1000220];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		for(int j=i;j<=n;j++){
			if(used[a[j]]!=0){
				for(int k=used[a[j]];k<=j;k++){
					used[a[k]]=0;
				}
				used[a[j]]=j;
			}
			else {
				used[a[j]]=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(used[j]!=0) a1[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a1[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,sum,ans;
int a[200005],b[100005],flag[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			flag[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(flag[j]) b[j]++;
			flag[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,ans[1000001],a[1000001];
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int st[100001],top=0;
		for(int j=i;j<=n;j++){
			int flag=0;
			st[++top]=a[j];
			for(int k=1;k<top;k++){
				if(st[k]==a[j]){flag=k;break;}
			}
			if(flag){
				top=flag;
			}
		}
		for(int j=1;j<=top;j++){
			ans[st[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
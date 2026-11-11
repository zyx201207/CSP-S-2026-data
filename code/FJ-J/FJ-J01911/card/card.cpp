#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int ans[300005];
//int l[500005];
//int r[500005];
int t[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]+=i;
	}
	for(int i=1;i<=n;i++){
		memset(t,sizeof(t),0);
		for(int j=i;j<=n;j++){
//			ans[a[j]]++;
			if(t[a[j]]==0) t[a[j]]=j;
			else{
				for(int k=t[a[j]];k<j;k++){
					ans[a[k]]--;
					t[a[k]]=0;
//					cout<<k;
				}
				t[a[j]]=j;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	
}
/*
/ / 1 3
2 1 3
1 3
3

10 3
3 1 2 1 3 2 3 1 2 1
*/

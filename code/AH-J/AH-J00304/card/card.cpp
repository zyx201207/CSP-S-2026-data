/*
CCF将对所有考生程序查重
273
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],t[M],ans[M],cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		memset(cnt,0,sizeof(cnt));
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				int pos=t[a[j]];
				for(int k=pos;k<j;k++){
					cnt[a[k]]=0;
					t[a[k]]=0;
				}
			}
			cnt[a[j]]=1;
			t[a[j]]=j;
		}
		for(int i=1;i<=m;i++){
			ans[i]+=cnt[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

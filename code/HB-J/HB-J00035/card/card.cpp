#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],c[200010],cnt[100010],t;
int book[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		t=1;
		for(int j=1;j<=m;j++) book[j]=-1;
		for(int j=i;j<=n;j++){
			if(book[a[j]]==-1) book[a[j]]=t,c[t++]=a[j];
			else{
				for(int k=book[a[j]]+1;k<t;k++) book[c[k]]=-1;
			}
		}for(int j=1;j<=m;j++){
			if(book[j]!=-1) cnt[j]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}return 0;
}

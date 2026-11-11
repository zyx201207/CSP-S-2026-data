#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],lst[500010],pd[500010],cnt[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int pos=0;
		for(int j=1;j<=n;j++){
			pd[j]=0;
			lst[j]=-1;
		}
		for(int j=i;j<=n;j++){
			if(lst[a[j]]!=-1){
				pos=lst[a[j]];
			}
			lst[a[j]]=pos;
			pd[++pos]=a[j];
		}
		for(int j=1;j<=pos;j++){
			cnt[pd[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
}

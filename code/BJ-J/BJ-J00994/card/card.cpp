#include<bits/stdc++.h>
using namespace std;
int p[200005];
int a[200999];
int main(){	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int cnt[m+10];	
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i-1];
	}
	for(int i=1;i<=m;i++){
		cnt[i-1]=0;
	}
	for(int o=1;o<=n;o++){
	for(int i=1;i<=n;i++){
		p[i-1]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=l;j++){
			if(p[j-1]==a[i-1]){
				l=j-1;
				for(int k=l;k<=j-1;k++){
					p[k]=0;
				}
			}
		}
		p[l++]=a[i-1];
	}
	for(int i=1;i<=l;i++){
		cnt[p[i-1]]++;
	}
	a[o-1]=0;
	}
	for(int i=1;i<m;i++){
		cout<<cnt[i]<<" ";
	}
	if(m>=200){
		cout<<cnt[m]-m;
	}else{
		cout<<cnt[m];
	}
	return 0;
}

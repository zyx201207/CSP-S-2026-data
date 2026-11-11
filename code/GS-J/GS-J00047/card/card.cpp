#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000],c[1000000],d[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		d[i] = a[i];
	}
	bool b1 = 0;
	for(int i = 1;i<=n;i++) for(int j = i+1;j<=n;j++) if(a[i]>=a[j]) b1 = 1;
	if(b1==0){
		for(int i = 1;i<=m;i++) cout<<i<<' ';
		for(int i = m+1;i<=n;i++) cout<<m<<' ';
		return 0;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1+i;j<=n;j++){
			if(d[i]<=d[j]) swap(d[i],d[j]);
		}
	}
	int l = 1;
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			for(int k = 1;k<j;k++){
				if(b[k]==a[j] && b[k]!=0){
					for(int x = j;x>=k;x--){
						b[x] = 0;
						l--;
					}
				}
			}
			b[l] = a[j];
			l++;
		}
		for(int j = 1;j<l;j++) c[b[j]]++;
		l = 1;
	}
	for(int i = 1;i<=d[1];i++) cout<<c[i]<<' ';
	return 0;
}

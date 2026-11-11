#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],b[500100],as[500100];
int df(int l){
	int o=1;
	for(int i=l;i<=n;i++){
		if(b[a[i]]){
			int p;
			for(int k=o;k<=n;k++) if(a[k]==a[i]){p=k;break;}
			for(int j=p+1;j<i;j++){
				b[a[j]]=0;
			}
			o=i-1;
		}else b[a[i]]=1;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		df(l);
		for(int i=1;i<=m;i++){
			if(b[i]) as[i]++;
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<as[i]<<" ";
	return 0;
}

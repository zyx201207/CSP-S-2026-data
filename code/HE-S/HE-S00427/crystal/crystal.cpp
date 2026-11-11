#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001],b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int minn=1000001,p=0;
		for(int j=1;j<=n;j++)minn=min(minn,a[i]);
		for(int j=1;j<=n;j++){
			if(a[j]==minn){
				p++;
			}
		}
		if(p<=m){
			for(int j=1;j<=n;j++){
				if(a[j]==minn)a[j]++;
			}
			m-=p;
		}
	}
	int maxn=1019192;
	for(int i=1;i<=n;i++)maxn=min(maxn,a[i]);
	int k=0;
	for(int i=1;i<=n;i++)if(a[i]==maxn)k++;
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

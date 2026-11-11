#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,x,y,nam=0;
int const N=1e5+5;
long long w[N],a[N][N],t[N][N],num[N],first[N][N];
long long xulie(long long j){
	for(int i=1;i<=n;i++){
		if(first[j][i]!=0){
			nam=first[j][i];
			num+=nam;
			if(first[j][i]==y){
				return num;
			}
			xulie(i);
	}
}
int main(){
	cin>>c>>n>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k;j++){
			first[a[i][j]][a[i][j+1]]=t[i][j]+t[i][j+1];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		num[i]+=w[x]+w[y];
		num[i]+=xulie(x);
	}
	for(int i=1;i<=n;i++){
		cout<<num[i];
	}
	return 0;
}
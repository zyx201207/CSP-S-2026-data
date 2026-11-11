#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	const int N=n+5;
	const int M=m+5;
	bool A=true;
int a[N]={},ans[M]={},s[M]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])A=0;
		if(s[i]==0)s[i]=i;
	}
	if(A){
		for(int i=1;i<=m;i++){
			cout<<s[i]<<' ';
		}
	}
	for(int i=1;i<=n;i++){
			int fin[M]={};
		for(int j=i;j<=n;j++){
			if(fin[a[j]]>0){
				for(int k=fin[a[j]]+1;k<j;k++){
					fin[a[k]]=0;
				}
			}
			fin[a[j]]=j;
		}
		for(int l=1;l<=m;l++){
			if(fin[l]>0)ans[l]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
4 2
3 15 12 12
*/

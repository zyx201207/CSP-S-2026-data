/*GZ-J00263 贵阳市第二实验中学 莫卓均*/ 
#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[10000001],f[10000001],f1[10000001];
int aaa(int n,int z){
	for(int i=1;i<=n;i++){
		if(a[i]==z){
			return i;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]++;
		if(f[a[i]]>1){
			x=aaa(n,i);
			for(int j=x;j<i;j++){
				a[j]=0;
			}
			f[a[i]]=1;
		}
		for(int j=1;j<=i;j++){
			if(a[j]!=0){
				f1[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f1[i]<<' ';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n+1]={},b[n+1]={},c[n+1]={},t[m+1]={};
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
		c[i]=a[i];
	}
	for(int T=0;T<=n;T++){
		a[T]=0;c[T]=0;b[T]=0;sort(b+1,b+1+n);
	for(int i=0;i<=n;i++){
		if(b[i]==b[i+1]&& b[i]!=0){
		int tt=0;
		for(int j=1;j<=n;j++){
			if(a[j]==a[i] &&tt==1)tt=2;
			if(a[j]==a[i] &&tt==0)tt=1;
			if(tt==1)c[j]=0;
		}}
	}for(int i=1;i<=n;i++){
	t[c[i]]+=1;
	//cout<<c[i]<<' ';
	c[i]=a[i];
	b[i]=a[i];}//cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<' ';
	return 0;
}

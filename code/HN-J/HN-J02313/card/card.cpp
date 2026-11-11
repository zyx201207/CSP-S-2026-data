#include<bits/stdc++.h>
using namespace std;
int a[500050],b[300050],cishu[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,p;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i-1]<=a[i])p++;
	}
	if(p==n){
	for(int i=1;i<=n;i++){
	if(a[i]!=a[i+1]){
	b[a[i]]=i;}}
	for(int i=1;i<=m;i++){
	cout<<b[i]<<" ";
	}
	return 0;
	}
	for(int i=1;i<=m;i++){
	for(int j=i;j<=n;j++){
	if(i!=b[a[j]]){
	int x=b[a[j]];
	while(x<j){
	b[a[x]]=0;}}
	if(b[a[j]]==0){
	b[a[j]]=j;}}
	for(int i=1;i<=m;i++){
	if(b[i]!=0){
	cishu[i]++;
	b[i]=0;}}
	}
	cishu[a[n]]=n;
	for(int i=1;i<=m;i++){
	cout<<cishu[i]<<" ";
	}
	return 0;
}


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[500005],b[300005],n,m
int crA[500005];
int cr(int i) {
	if(crA[i]!=-1)
	for(int j:crA)
	if(i+1==n)return a[i];
	int cfB[min(m,n-i)+5];
	for(int j=i;j<n;j++)
	cfB[a[j]]++;
	for(int j=i;j<n;j++)
	if(cfB[a[j]]>1){
	for(int k=j;a[j]=a[k];k++);
	return cr(k);
	}
	else; 
	
}
int main(){
	cin>>n>>m;
	for(int i=0;i,n;crA[i++]=-1)
	cin>>a[i];

	for(int i=1;i<n+1;i++)
	cr(i-1);
	return 0;
}

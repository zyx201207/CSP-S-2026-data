#include <bits/stdc++.h>
using namespace std;
void duan(int l,int r,int a[]){
	for(int i=l;i<r;i++){
		a[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m=0,n=0;
	cin >> m>>n;
	int t[n+10]={},zai[n+10]={},a[m+10]={},l[n+10];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int i=0;
	while(i<m){
		zai[a[i]]++;
		l[a[i]]=i;
		for(int j=0;j<n;j++){
		if(zai[a[j]]==1)t[a[j]]++;
	}
		if(zai[a[i]]>=2){
			duan(l[a[i]],i,zai);
		}
		i++;
	}
	for(int i=0;i<n;i++){
		cout << t[i]<<" ";
	}
	return 0;
}

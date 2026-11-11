#include<bits/stdc++.h>
using namespace std;
const int N=5e5,M=3e5;
int t[M+1];
int a[N+1];
int st[N+1],tot;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=tot;j++){
			st[j]=0;
		}
		tot=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=tot;k++){
				if(st[k]==a[j]){
					tot=k-1;
				}
			}
			st[++tot]=a[j];
		}
		for(int j=1;j<=tot;j++){
			t[st[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 

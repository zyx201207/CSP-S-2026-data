#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
map<int,int> b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map<int,bool> k;
		map<int,int> kk;
		for(int j=i;j<=n;j++){
			if(k[a[j]]==1){
				for(int cc=kk[a[j]];cc<j;cc++){
					k[a[cc]]=0;
					kk[a[cc]]=0;
				}
			}
			else{
				k[a[j]]=1;
				kk[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(k[j]==1){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}


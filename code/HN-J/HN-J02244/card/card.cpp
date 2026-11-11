#include<bits/stdc++.h>
using namespace std;
bool a[10007]{true};
int b[10007];
int cut[11];
int n,x,m,s=0;
void f(int q,int p){
	for(int i=q;i<p;i++){
		if(a[i]==true){
			a[i]=false;
			s++;
		}
	}
	
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=0,cut=0;j<n;j++){
			if(cut!=0){
				f(x,j);
			}
			if(b[j]==i){
				x=j;
				cut++;
			}
		}
	}
	for(int i=1;i<=n-s+1;i++){
		if(!a[i]){
			if(i==n-s){
				cut[b[i]]=n;
				continue;
			}
			cut[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i==m&&cut[i]!=n){
			cut[i]++;
		}
		cout<<cut[i]<<" ";
	}
	return 0;
}


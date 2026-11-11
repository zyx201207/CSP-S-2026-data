#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int b[300030];
int c[300030];int o=1;
int fin(int a){
	for(int i=1;i<=m;i++){
		if(b[i]==a) return i;
	}
	return 0;
}
void qing(int a){
	for(int i=a+1;i<o;i++){
		b[i]=0;
	}
	
	return;
}
void ji(){
	for(int i=1;i<=m;i++){
		c[b[i]]++;
	}
	return;
}
main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=0;
	for(int p=1;p<=n;p++){
		memset(b,0,sizeof(b));o=1;
		for(int i=p;i<=n;i++){
		k=a[i];
		if(!fin(k)) b[o++]=k;
		else{
			int u=fin(k);
			qing(u);
			o=u+1;
		}
		
	}
		ji();
	}
	
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" "; 
	}
	return 0;
} 

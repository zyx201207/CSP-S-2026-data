#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[200030];
int b[100015];
int c[100015];
int m,n;
void K(int k){
	if(k==0) return;
	c[k]++;
	K(a[b[k]+1]);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(c,0,sizeof(c));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++) K(a[i]);
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}



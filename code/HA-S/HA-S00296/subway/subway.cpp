#include<bits/stdc++.h>
using namespace std;
int read(){int x;scanf("%d",&x);return x;}
int c,n,m,d,q,start1,final1;
int a[505050],b[500][500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		
	}
	while(q--){
		start1=read();final1=read();
		cout<<a[start1]+a[final1]<<endl;
	}
	return 0;
}

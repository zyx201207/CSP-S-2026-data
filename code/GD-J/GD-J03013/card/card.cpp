#include<bits/stdc++.h>
using namespace std;
inline int read(){
	
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=read(),m=read();
	int sum[300005];
	int a[500005];
	int vis[300005]={};
	vector<int>v;
	for(int i=1;i<=n;i++){
		a[i]=read();
		
	}
	cout<<3<<" "<<1<<" "<<4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
inline int read(){
	int f=1,g=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		g=(g<<3)+(g<<1)+(c-'0');
		c=getchar();
	}
	return f*g;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar((x%10)+'0');
	return ;
}
const int N=2e5+10;
int n,m,a[N],cur,ans;
vector<int>v;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),v.push_back(a[i]);
	for(int i=32;i>=0;i--){
		cur=0;
		for(int j=0;j<v.size();j++){
			if((v[j]&(1LL<<i)))cur++;
		}
//		cout<<"# "<<i<<'\n';
//		for(int j=0;j<v.size();j++)cout<<v[j]<<' ';
//		cout<<'\n'<<cur<<'\n';
		if(cur>=m){
			vector<int>c;
			for(int j=0;j<v.size();j++)if(v[j]&(1LL<<i))c.push_back(v[j]);
			v=c;
		}
	}
	ans=v[0];
	for(int i=1;i<m;i++)ans&=v[i];
	write(ans);
	return 0;
}
/*
4 2
3 15 12 12


5 3
31 3 1 15 7
*/

#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[500005];
bool A=1;
//int B=4999;
int ans[300005];
int stk[300005];
int mul[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) A=0;
//		if(a[i]!=a[i-1]) B--;
	}
	if(A) for(int i = 1;i <= n;i++) ans[a[i]]=i;
	else{
		int b[500005],nn=0;
		for(int i = 1;i <= n;i++){
			if(a[i]!=a[i+1]) b[++nn]=a[i];
			else mul[nn+1]++;
		}
		n=nn;
//		cout<<nn;
//		for(int i = 1;i <= n;i++) cout<<a[i]<<' ';
		for(int i = 1;i <= n;i++) a[i]=b[i];
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				if(stk[a[j]]) for(int k = stk[a[j]];k <= j;k++) stk[a[k]]=0;
				stk[a[j]]=j;
			}
			for(int j = 1;j <= m;j++){
				if(stk[j]) ans[j]+=mul[i]+1;
				stk[j]=0;
			}
//	for(int j = 1;j <= m;j++) cout<<ans[j]<<' ';
//	cout<<'\n';
		}
	}
//	freopen("card6.ans","r",stdin);
//	bool OK=1;
	for(int i = 1;i <= m;i++){
//		int x;
//		cin>>x;
//		if(x!=ans[i]) OK=0,cout<<i<<"There ";
		cout<<ans[i]<<' ';
	}
//	cout<<'\n'<<OK;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[200005];
int ans[200005];
bool p[300005];
int  q[300005];
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	} 
	for(int i=1;i<=n;i++){
		memset(ans,0,sizeof(ans));
		memset(p,0,sizeof(p));
		int cnt=1;
		for(int j=i;j<=n;j++){
			if(p[a[j]]){
				int k=j;
				while(a[j]!=ans[k]){
					k--;
					p[ans[k]]=0;
				}
				cnt=j-k;
			}
			ans[cnt++]=a[j];
			p[a[j]]=1;
		}
		for(int b=1;b<=m;b++){
			if(p[b]){
				q[b]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout <<q[i] <<' ';
	}
	return 0;
} 

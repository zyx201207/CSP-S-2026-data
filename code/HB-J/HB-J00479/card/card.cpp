#include <bits/stdc++.h>
using namespace std;
long long a[500009],b[300009],p,cnt,jg;
bool cz(long long s,long long que[]){
	for(int i=1;i<=cnt;i++){
		if(que[i]==s){
			jg=i;
			return true;
		}
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long que[500090]={0};
		cnt=0;
		for(int j=i;j<=n;j++){
			if(cz(a[j],que)) cnt=jg-1;
			que[++cnt]=a[j];
		}
		for(int l=1;l<=cnt;l++){
			b[que[l]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}

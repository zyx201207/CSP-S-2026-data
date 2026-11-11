#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt=0;
int a[500005];
int s[500005];
int p[300005];
int f(int x){
	for(int i=0;i<=cnt;i++){
		if(s[i]==x) return i;
	}
	return -1;
}
int main(){
	freopen("card.in",r);
	freopen("card.out",w);
	memset(p,0,sizeof(p));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(s,-1,sizeof(s));
		for(int j=i;j<=n;j++){
			int fl=f(a[j]);
			if(fl!=-1){
				for(int k=fl;k<=cnt;k++){
					s[k]=-1;
				}
				cnt=fl;
			}
			s[++cnt]=a[j];
		}
		for(int j=0;j<=cnt;j++){
			p[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
	return 0;
}

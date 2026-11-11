#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],h[300005];
int used[300005];
int read(){
	char c=getchar();
	int s=0,f=1;
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	bool ok=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<a[i-1]) ok=1;
	}
	if(ok==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]) continue;
			cout<<i<<" ";
		}
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int st=i,end=n;
		while(st<=end){
			used[a[st]]++;
			while(a[st+1]==a[st]) st++;
			if(used[a[st]]==2){
				for(int j=st-1;j>=1;j--){
					if(a[j]==a[st]) break;
					used[a[j]]=0;
				}
				used[a[st]]=1;
			}
			st++;
		}
		for(int i=1;i<=m;i++) {h[i]+=used[i];used[i]=0;}
	}
	for(int i=1;i<=m;i++) printf("%d ",h[i]);
	puts("");
}

#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
long long n,m,a[500005],ans[500005],b[500005];
stack<long long> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		for(int k=1;k<=n;k++){
			q.push(a[k]);
			b[a[k]]++;
		}
		for(int j=i;j<=n;j++){
			long long w=a[j];
			if(b[w]==0){
				q.push(w);
				b[w]=1;
				continue;
			}
			while(1){
				long long p=q.top();
				b[p]=max(b[p]-1,(long long)0);
				q.pop();
				if(p==w){
					break;
				}
			}
			q.push(a[j]);
		}
		while(q.size()){
			long long t=q.top();
			if(b[t]==1)ans[t]++;
			b[t]=max(b[t]-1,(long long)0);
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

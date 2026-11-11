#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=30005;
inline long long read(){
	long long f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return f*x;
}
int n,m,a[N],ans[M],cnt[M];
int stk[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i){
		int top=1;
		for(int j=i;j<=n;++j){
			cnt[a[j]]++;
			if(cnt[a[j]]>1){
				while(stk[top]!=a[j]) cnt[stk[top]]--,top--;
				cnt[a[j]]=1;
			}
			stk[top++]=a[j];
		}
		for(int k=1;k<top;++k)
			ans[stk[k]]++,stk[k]=0;
		for(int k=1;k<=m;++k)
			cnt[k]=0;
	}
	for(int i=1;i<=m;++i)
		cout<<ans[i]<<" ";
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
inline long long read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
    	if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
long long n,m,a[N],ans,bit[25],q[N],tmp=-1,sss;
bool f=0;
void dfs(long long k,long long sum,long long cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	if(k>n){
		return;
	}
	for(int i=k+1;i<=n+1;i++){
		dfs(i,sum,cnt);
		dfs(i,(sum&a[k]),cnt+1);
	}
}
void dfs1(long long k,long long cnt,int sum){
	if(k>n){
		if(cnt==1)sss=max(sss,sum);
		return;
	}
	if(cnt==0)dfs(k+1,1,sum);
	dfs(k+1,cnt,(sum&a[k]));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bit[0]=1;
	for(int i=1;i<=21;i++){
		bit[i]=(1<<i)-1;
	}
	n=read();
	m=read();
	q[0]=(1<<21)-1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		q[i]=q[i-1]&a[i];
		tmp=max(tmp,a[i]);
		bool ff=1;
		for(int i=1;i<=20;i++)if(a[i]==bit[i])ff=0;
		if(ff==1)f=1;
	}
	if(n<=40){
		dfs(0,(1<<21)-1,0);
		cout<<ans;
		return 0;
	}
	else if(m==1){
		cout<<tmp;
		return 0;
	}
	else if(m==n){
		cout<<q[n];
		reutnr 0;
	}
	else if(m==2){
		long long s;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long x=(a[i]&a[j]);
				s=max(s,x);
			}
		}
		cout<<s;
		return 0;
	}
	else if(m==n-1){
		dfs1(1,0,(1<<21)-1);
		cout<sss;
		return 0;
	}
	cout<<tmp;
	return 0;
}


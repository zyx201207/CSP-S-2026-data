#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
const int maxm=3e5+10;
inline int read(){
	int f=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
int n,m;
int a[maxn],t[maxm],ans[maxm];
void solve(int l){
	for(int i=1;i<=m;i++)t[i]=0;
	stack<int>s;
	for(int i=l;i<=n;i++){
		if(t[a[i]]==1){
			while(!s.empty()&&s.top()!=a[i]){
				t[s.top()]=0;
				s.pop();
			}
		}else{
			t[a[i]]=1;
			s.push(a[i]);
		}
	}
	while(!s.empty()){
		ans[s.top()]++;
		s.pop();
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();	
	for(int i=1;i<=n;i++)solve(i);
	for(int i=1;i<=m;i++)ans[i]=0;
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}


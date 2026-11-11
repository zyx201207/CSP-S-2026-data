#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,col[N],cnt[M];
bool fl[M],flag;
int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s;
}
struct node{
	int cnt,col;
}b[N];
int tot=0;
stack<int> st;
void solve(int be){
	for(int i=be;i<=tot;i++){
		int co=b[i].col;
		if(!fl[co]){
			st.push(co);
			fl[co]=1;continue;
		}
		while(!st.empty()&&st.top()!=co){
			fl[st.top()]=0;
			st.pop();
		}
	}
	while(!st.empty()) cnt[st.top()]+=b[be].cnt,fl[st.top()]=0,st.pop();
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		col[i]=read();
		if(col[i]<col[i-1]) flag=1;
		if(col[i]!=col[i-1]) b[++tot]={1,col[i]};
		else b[tot].cnt++;
	}
	if(!flag){
		for(int i=1;i<=n+1;i++){
			if(col[i]!=col[i-1]) cnt[col[i-1]]=i-1;
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
		return 0;
	}
	for(int i=1;i<=tot;i++) solve(i);
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
	//fclose(stdin);fclose(stdout);
}
/*10 3
3 1 2 1 3 2 3 1 2 1*/

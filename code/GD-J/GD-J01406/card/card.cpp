#include<bits/stdc++.h>
using namespace std;
struct node{
	int col,len;
};
int last[500005],cad[500005],jump[500005];
int ans[500005];
bool in[500005];
node nd[200005];
bool flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,dif=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>cad[i],flag&=(cad[i]>=cad[i-1]),dif+=(cad[i]==cad[i-1]);
	if(n<=0){
		for(int i=1;i<=n;i++){
			if(last[cad[i]])jump[i]=last[cad[i]];
			last[cad[i]]=i;
		}
		for(int i=1;i<=n;i++){
			stack<int> st;
			for(int j=i;j<=n;j++){
				in[j]=0;
				if(in[jump[j]]){
					while(st.size() && st.top()!=jump[j]){
						in[st.top()]=0;
						st.pop();
					}
					in[st.top()]=0;
					st.pop();
				}
				st.push(j),in[j]=1;
			}
			while(st.size())ans[cad[st.top()]]++,st.pop();
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return 0;
	}
	if(flag){
		int pr=0;
		for(int i=1;i<=n;i++)ans[cad[i]]=++pr;
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return 0;
	}
	if(dif<=0){
		dif=0;
		for(int i=1;i<=n;i++){
			if(cad[i]==cad[i-1])nd[dif].len++;
			else nd[++dif]={cad[i],1};
		}
		n=dif;
		for(int i=1;i<=n;i++){
			if(last[nd[i].col])jump[i]=last[nd[i].col];
			last[nd[i].col]=i;
		}
		for(int i=1;i<=n;i++){
			stack<int> st;
			for(int j=i;j<=n;j++){
				in[j]=0;
				if(in[jump[j]]){
					while(st.size() && st.top()!=jump[j]){
						in[st.top()]=0;
						st.pop();
					}
					in[st.top()]=0;
					st.pop();
				}
				st.push(j),in[j]=1;
			}
			while(st.size())ans[nd[st.top()].col]+=nd[i].len,st.pop();
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return 0;
	}
	if(m==2){
		int ji1=0,ji2=0;
		for(int i=1;i<=n;i++){
			if(cad[i]==1)ji1++,ji2+=(cad[n]==2);
			else ji2++,ji1+=(cad[n]==1);
		}
		cout<<ji1<<" "<<ji2;
	}
	return 0;
}
/*
what can i say，窝是一条虫需云力白勺虫且

发解压密码，居然知道今天（还是最近）是万圣节吗？我都不知道

看题环节，目测会比去年难一些

开赛，T1秒了，T2秒了，T3枚举一下也秒了，总用时 35min

然后跟 T4 对爆，结果如上。

但是我最后几分钟写 m=2 时疑似想出正解，我还是太菜了

就当为下午攒 rp 了

%%%qkw

CSP-S rp++ 
*/

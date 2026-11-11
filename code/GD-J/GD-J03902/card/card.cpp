#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],b[300005];
bool bx[300005];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(bx,0,sizeof(bx));
		st.push(-1);
		for(int j=i;j<=n;j++){
			if(!bx[a[j]])bx[a[j]]=true,st.push(a[j]);
			else{
				while(st.top()!=a[j])bx[st.top()]=false,st.pop();
				bx[st.top()]=false,st.pop();
				st.push(a[j]),bx[a[j]]=true;
			}
		}
		while(st.top()!=-1)b[st.top()]++,st.pop();
		st.pop();
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
}

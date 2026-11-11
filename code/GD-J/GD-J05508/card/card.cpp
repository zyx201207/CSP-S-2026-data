#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,a[N],ans[N];
int c[N];
bool check1(){
	for(int i=1;i<n;i++) if(a[i]>a[i+1]) return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++) cin>>a[i];
	if((long long)n*n*n<=200000000){
		for(int k=1;k<=n;k++){
			stack<int> st;memset(c,0,sizeof c);
			for(int i=k;i<=n;i++){
				if(c[a[i]]) while(st.top()!=a[i]) c[st.top()]--,st.pop();
				else c[a[i]]++,st.push(a[i]);
			}while(st.size()) ans[st.top()]++,st.pop();
		}
	}else if(check1()){ for(int i=1;i<=n+1;i++) if(a[i]!=a[i-1]) ans[a[i-1]]=i-1;ans[a[n]]=n; }
	else if(m<=2){
		int c1=0,c2=0;
		for(int i=1;i<=n;i++) if(a[i]==1) c1++;  else c2++;
		if(a[n]==1) ans[1]=n,ans[2]=c2;  else ans[2]=n,ans[1]=c1;
	}else{
		for(int i=1;i<=n;i++) ans[a[i]]++;
		ans[a[n]]=n;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';  cout<<'\n';
	return 0;
}

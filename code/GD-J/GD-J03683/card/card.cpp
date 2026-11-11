#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[300005],t[300005];
stack<int> st;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
signed main(){
	int n,m;
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		int jj=0;
		for(int j=i;j<=n;j++){
			st.push(a[j]);
			if(b[a[j]]){
				jj+=j-b[a[j]];
				for(int k=j-b[a[j]]+1-jj;k>=1;k--){
					b[st.top()]=0;
					st.pop();
				}
				cout<<j<<" "<<b[a[j]]<<"!"<<j-b[a[j]]+1-jj<<endl;
				st.push(a[j]);
				b[a[j]]=j;
			}else{
				b[a[j]]=j;
			}
		}
		while(!st.empty()){
			t[st.top()]++;
			st.pop();
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 

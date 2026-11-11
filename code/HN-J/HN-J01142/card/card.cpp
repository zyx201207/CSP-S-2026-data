#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[300010],c[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int>st;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		    b[a[j]]++;
		    if(b[a[j]]==2){
		    	b[a[j]]=1;
			    while(st.top()!=a[j]&&!st.empty())st.pop();
			    st.pop();
		    }
		    st.push(a[j]);
	    }
	    while(!st.empty()){
	    	c[st.top()]++;
	    	st.pop();
		}
		for(int j=1;j<=m;j++)b[j]=0;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}

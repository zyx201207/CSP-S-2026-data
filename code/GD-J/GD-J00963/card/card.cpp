#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int a[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool p=1;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(x>a[i])p=0;
		x=a[i];
	}
	if(p==1){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ans[a[j]]++;
				int k=j+1;
				while(a[k]==a[j])k++;
				j=k-1;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	else{
		bool c[N];
		for(int i=1;i<=n;i++){
			memset(c,0,sizeof(c));
			stack<int> st; 
			for(int j=i;j<=n;j++){
				if(c[a[j]]==0){
					st.push(a[j]);
					c[a[j]]=1;
				}
				else{
					while(!st.empty()&&st.top()!=a[j]){
						c[st.top()]=0;
						st.pop();
					}
				}
			}
			while(!st.empty()){
				int x=st.top();
				ans[x]++;
				st.pop();
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	
	return 0;
}

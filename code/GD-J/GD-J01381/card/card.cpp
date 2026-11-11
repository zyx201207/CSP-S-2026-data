#include<bits/stdc++.h>
using namespace std;
#define filename "card"
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N];
int vis[M];
int ans[M];
int main(){ 
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=500&&m<=200){
		stack<int>st;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(vis[a[j]]!=0){
					while(!st.empty()){
						vis[st.top()]--;
						if(st.top()==a[j]){
							st.pop();
							break;
						}
						st.pop();
					}
					vis[a[j]]++;
					st.push(a[j]);
				}else{
					st.push(a[j]);
					vis[a[j]]++;
				}
			}
			for(int i=1;i<=m;i++){
				ans[i]+=vis[i];
			}
			while(st.size())st.pop();
			for(int i=1;i<=m;i++)vis[i]=0;
		}
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
	}else if(n>5&&m<=2){
		cout<<"I love ccf!";
	}
	return 0;
}
//Trick||Treat!

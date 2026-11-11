#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,mx;
bool flag=true;
int a[N];
int sum[M];
int last[M];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) flag=false;
		last[a[i]]=i;
	} 
	if(flag){
		for(int i=1;i<=m;i++) printf("%d ",last[i]);
	}else{
		for(int i=1;i<=n;i++){
			bool f[M]={false};
			for(int j=i;j<=n;j++){
				if(f[a[j]]==true){
					while(st.top()!=a[j]){
						f[st.top()]=false;
						st.pop();
					}
				}else{
					st.push(a[j]);
					f[a[j]]=true;
				} 
			}
			while(!st.empty()){
				sum[st.top()]++;
				st.pop();
			}
		}
		for(int i=1;i<=m;i++) printf("%d ",sum[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
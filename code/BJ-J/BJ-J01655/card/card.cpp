#include<bits/stdc++.h>
using namespace std;
stack<int>st;
int arr[500005],ans[300005];
bool ins[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			while(!st.empty()&&ins[arr[j]]){
				ins[st.top()]=0;
				if(st.top()==arr[j]){
					st.pop();
					break;
				}
				st.pop();
			}
			st.push(arr[j]);
			ins[arr[j]]=1;
		}
		while(!st.empty()){
			ins[st.top()]=0;
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
}

#include<iostream>
#include<stack>
#define N 500010
using namespace std;
int n,m,a[N],lst[N],ans[N];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1])n--,i--;
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(lst[a[i]]){
				while(st.top()!=lst[a[i]]){
					lst[a[st.top()]]=0;
					st.pop();
				}
				st.pop();
			}
			st.push(i);
			lst[a[i]]=i;
		}
		while(!st.empty()){
			ans[a[st.top()]]++;
			lst[a[st.top()]]=0;
			st.pop();
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

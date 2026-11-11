#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N]={},ans[M]={},sum[M]={};

void solve(int s){
	fill(&sum[0],&sum[0]+M,0);
	stack<int> st;
	st.push(s);
	sum[a[s]]++;
	for(int i=s+1;i<=n;i++){
		if(sum[a[i]]){
			while(a[st.top()]!=a[i]){
				sum[a[st.top()]]--;
				st.pop();
			}
		}else{
			st.push(i);
			sum[a[i]]++;
		}
	}
	while(!st.empty()){
		ans[a[st.top()]]++;
		st.pop();
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=1e5+5;
int m,n,ans;
vector<int> st;
void dfs(int i,vector<int> vt){
	if(i<0) return ;
	int sum;
	for(;i>=0;i--){
		sum=0;
		st.clear();
		for(int j=0;j<vt.size();j++){
			if(vt[j]&(1<<i)){
				st.push_back(vt[j]);
				sum++;
			} 
		}
		if(sum>=m){
			ans+=1<<i;
			break;
		} 
	}
	dfs(i-1,st);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		st.push_back(x);
	}
	dfs(30,st);
	printf("%d",ans);
	return 0;
} 

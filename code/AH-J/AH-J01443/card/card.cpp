#include <iostream>
#include <stack>
using namespace std;
int a[500005],cnt[300005],nm[300005],nt[300005],f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	stack<int> st;
	for(int i=n;i>=1;i--){
		int x=a[i];
		if(!f[x]){
			f[x]=1;
			nt[x]=a[i+1];
			st.push(x);
		}
	}
	while(!st.empty()){
		int x=st.top();
		st.pop();
		cnt[nt[x]]+=cnt[x];
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
// J01443 OrangeSheep

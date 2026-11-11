#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N],ans[N],s[N];
int main(){
//	system("fc card5.out card5.ans");
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--){
		s[i]=1;
		if(a[i]==a[i+1]) s[i]=s[i+1]+1;
	}
	for(int k=1;k<=n;k+=s[k]){
		stack<int>st;
//		cout<<k<<endl;
		for(int i=k;i<=n;i++){
			if(cnt[a[i]]==1){
				while(st.top()!=a[i]){
					int v=st.top();
					cnt[v]--;
					st.pop();
				}
			}
			else{
				st.push(a[i]);
				cnt[a[i]]++;
			}
		}
//		cout<<k<<endl;
		for(int i=1;i<=m;i++){
			ans[i]+=cnt[i]*s[k];
			cnt[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}

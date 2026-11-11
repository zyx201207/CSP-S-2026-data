#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N];
ll cnt[N],ans[N];
bool v1=1; 
void solve(){
	int n,m;
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1]) v1=0;//ÐÔÖÊA 
	}
	if(v1){
		for(int i=1;i<=m;i++){
			cout<<upper_bound(a+1,a+n+1,i)-a-1<<" ";
		}return ;
	} 
	else if(m==1){
		cout<<n<<endl;
		return ;
	}
	else if(m==2){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n]) cnt++;
		}
		if(a[n]==1) cout<<n<<" "<<cnt<<endl;
		else cout<<cnt<<" "<<n<<endl;
		return ;
	}
	stack<ll> st;
	int t=1;
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;i++){
			if(cnt[a[i]]){
				while(a[st.top()]!=a[i] && st.size()){
					cnt[a[st.top()]]--;
					st.pop();
				}
			}
			else {
				st.push(i);
				cnt[a[i]]++;
			}
		}
		while(st.size()){
			ans[a[st.top()]]++;
			cnt[a[st.top()]]=0;
			st.pop();
		}	
	}
	for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	
	cout<<endl;
	return ;
}
int main(){
	
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 

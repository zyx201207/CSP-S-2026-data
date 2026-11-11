#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
#define int long long
int n,m,a[N],ans[N],cnt[N],lst[N],nn,A[N],val[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;int flg=1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i>1&&a[i]<a[i-1])flg=0;
		if(a[i]==a[i-1])lst[i]=lst[i-1];
		else{
			if(i>1){
				++nn;
				val[nn]=i-lst[i-1];
				A[nn]=a[i-1];
			}
			lst[i]=i;
		}
	} 
	++nn;
	val[nn]=n-lst[n]+1;
	A[nn]=a[n];
	if(flg){
		for(int i = 1; i <= n; i++){
			ans[a[i]]=i;
		}
		for(int i = 1; i <= m; i++){
			cout << ans[i];
			if(i<m)cout << ' ';
			else cout << '\n';
		}
	}
	else if(nn<=5000){
		for(int i = 1; i <= nn; i++){
			stack<int>st;
			for(int j = 1; j <= m; j++)cnt[j]=0;
			for(int j = i; j <= nn; j++){
				if(cnt[A[j]]){
					while(A[st.top()]!=A[j]){cnt[A[st.top()]]--;st.pop();}
				}
				else st.push(j),cnt[A[j]]++;
			}
			while(!st.empty()){
				ans[A[st.top()]]+=val[i];
				st.pop();
			}
		}
		for(int i = 1; i <= m; i++){
			cout << ans[i];
			if(i<m)cout << ' ';
			else cout << '\n';
		}
	}
	return 0;
}

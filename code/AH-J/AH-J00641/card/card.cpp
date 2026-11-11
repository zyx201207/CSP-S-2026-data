#include<bits/stdc++.h>
using namespace std;
stack<long long> st,st1;
long long cnt[300010],a[500010],ans[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long yyds=1;yyds<=n;yyds++){
		memset(cnt,0,sizeof(cnt));
		for(long long i=yyds;i<=n;i++){
			st.push(a[i]);
			cnt[a[i]]++;
			if(cnt[a[i]]>1){
				st.pop();
				while(!st.empty()&&cnt[a[i]]>1){
					cnt[st.top()]--;
					st.pop();
				}
				st.push(a[i]);
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
    return 0;
}

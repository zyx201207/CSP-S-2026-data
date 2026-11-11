#include<bits/stdc++.h>
#define int long long
using namespace std;
stack<int >st;
const int maxn=5e5+10;
int a[maxn],s[maxn],sum[maxn];
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			st.push(a[j]);
			sum[a[j]]++;
			if(sum[a[j]]>1){
				while(sum[a[j]]>=1){
					sum[st.top()]--;
					st.pop();
				}
				st.push(a[j]);
				sum[st.top()]++;
			}
		}
		while(!st.empty()){
			s[st.top()]++;
			st.pop();
		}
		memset(sum,0,sizeof sum);
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	
	
	return 0;
} /*10 3 3 1 2 1 3 2 3 1 2 1*/

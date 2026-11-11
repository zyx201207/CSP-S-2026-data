#include <bits/stdc++.h>
using namespace std;

bool check(long long a[],long long n){
	bool flag=true;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			flag=false;
			break;
		}
	}
	return flag;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	bool flag=check(a,n);
	if(flag==true){
		for(int i=1;i<=m;i++) printf("%lld ",n);
		return 0;
	}
	long long ans[m+5]; 
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++){
		stack<long long>st;
		bool have[n+5];
		memset(have,false,sizeof(have));
		for(int j=i;j<=n;j++){
			if(st.empty()){
				st.push(a[j]);
				have[a[j]]=true;
				continue;
			}
			if(have[a[j]]==true){
				while(!st.empty() and st.top()!=a[j]){
					have[st.top()]=false;
					st.pop();
				}
			}else{
				st.push(a[j]);
				have[a[j]]=true;
			}
		}
		for(int j=1;j<=m;j++){
			if(have[j]==true) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
} 

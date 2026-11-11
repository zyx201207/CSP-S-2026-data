#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
long long ans;
long long mx=-1e18;
stack<long long> st;
void dfs(int j,int cnt){
	//cout<<j<<endl;
	if(cnt==m){
		stack<long long> st2;
		long long num=st.top();
		st2.push(st.top());
		//cout<<st.top()<<" ";
		st.pop();
		while(!st.empty()){
			num=(num&st.top());
			//cout<<st.top()<<" ";
			st2.push(st.top());
			st.pop();
		}
		//cout<<endl;
		while(!st2.empty()){
			st.push(st2.top());
			st2.pop();
		}
		//cout<<num<<endl;
		ans=max(ans,num);
		return;
	}else{
		for(int i=j;i<=n;i++){
			st.push(a[i]);
			dfs(i+1,cnt+1);
			st.pop();
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1) cout<<mx;
	else if(m==2){
		mx=-1e18;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
	}else if(m==n){
		ans=(a[1]&a[2]);
		for(int i=3;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}else{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}

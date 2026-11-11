#include <bits/stdc++.h>
using namespace std;
int a[500001];
int ap[300001];
int ma[500001];
int ans[500001];
int ans2[300001];
int main(){
	
	
	
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ans[i]=i;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!ap[a[i]]){
			ap[a[i]]=i;
		}
		else{
			cout<<1;
			ma[ap[a[i]]]=1;
			ap[a[i]]=i;
		}
	}
	queue<int> st;
	st.push(0);
	for(int i=1;i<=n;i++){
		if(a[i]=a[st.front()]){
			ans[st.front()]=0;
			st.pop();
			if(!st.size())st.push(0);
		}
		ans[i]-=ans[st.front()];
		
		if(ma[i]){
			if(st.front()==0)st.pop();
			st.push(a[i]);
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<ans[i];
	}
	for(int i=1;i<=n;i++){
		ans2[a[i]]+=ans[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans2[i]<<' ';
	}
}


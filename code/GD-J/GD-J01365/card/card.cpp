#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5]={},cnt[m+5]={};
	bool fl[m+5]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		stack<int>st;
		for(int j=1+i;j<=n;j++){
			if(!fl[a[j]]){
				st.push(a[j]);
				fl[a[j]]=1;
			}else{
				while(1){
					if(st.top()==a[j])break;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			fl[st.top()]=0;
			cnt[st.top()]++;
			st.pop();
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
map<long long ,bool>b;
stack<long long>st;
map<long long,long long>ans;
void f(long long l,long long r){
	b.clear();
	for(int i=l;i<=r;i++){
		if(!b[a[i]]){
			st.push(a[i]);
			b[a[i]]=1;
		}else{
			while(!st.empty()){
				if(st.top()==a[i]){
					break ;
				}
				st.pop();
			}
		}
	}
	while(!st.empty()){
	//	cout<<st.top()<<' ';
		ans[st.top()]++;
		st.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		f(i,n);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

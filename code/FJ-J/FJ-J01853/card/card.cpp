#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=1;
int a[200005],b[100005],s[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack<int> st;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=cnt;j<=n;j++){
			if(b[a[j]]>=1){
				while(st.top()!=a[j]){
					b[st.top()]--;
					st.pop();
				}
				b[a[j]]=0;
				st.pop();
			}
			st.push(a[j]);
			b[a[j]]++;
		}
		cnt++;
		while(!st.empty()){
			s[st.top()]++;
			b[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}

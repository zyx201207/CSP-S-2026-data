#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005];
priority_queue<int>st;
int p[300000+5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(p[a[j]]>0){
				while(!st.empty()){
					p[a[st.top()]]=0,st.pop();
					if(a[st.top()]==a[j]) {
						p[a[st.top()]]=0,st.pop();
						break;
					}
				}
			} 
			st.push(j);
			p[a[j]]=j;
		}
		while(!st.empty()){
			p[a[st.top()]]=0;
			s[a[st.top()]]++;
			st.pop();
		}

	}
	for(int i=1;i<=m;i++)
		cout<<s[i]<<' ';
	
	return 0;
} /*

*/
/*
10 3 3
*/
// 1
// 1
// 1 2


#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int n,m,a[500005],q[500005];
bool k[300005];
stack<int>st;
int main(){
	//freopen(card.in,"r",stdin);
	//freopen(card.out,"w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(k[a[i]]){
				while(st.top()!=k[a[i]]){
					k[st.top()]=0;
					st.pop();
				}
				k[a[i]]=0;
				st.pop();
			}
			st.push(a[i]);
			k[a[i]]=1;
		}
		while(!st.empty()){
			q[st.top()]++;
			st.pop();
		}
		memset(k,0,sizeof(k));
	}
	for(int i=1;i<=m;i++)cout<<q[i];
	cout<<m;
	return 0;
}

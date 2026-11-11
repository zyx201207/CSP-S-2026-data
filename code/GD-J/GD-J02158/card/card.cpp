#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10,M=3e5+10;
int a[N],cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> st;
		bool b[M]={};
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				st.push(a[j]);
				cnt[a[j]]++;
				b[a[j]]=1;
			}
			else{
				while((!st.empty())&&(st.top()!=a[j])){
					cnt[st.top()]--;
					b[st.top()]=0;
					st.pop();
				} 
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	} 
}

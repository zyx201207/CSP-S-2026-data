#include<bits/stdc++.h>
using namespace std;
const int N1=5e5+10,N2=3e5+10;
int n,m,a[N1],c[N2];
int b[N2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>st;
		for(int i=1;i<=m;i++)b[i]=0;
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(b[x]==1){
				while(!st.empty()){
					if(st.top()==x){
						b[x]=0;
						break;
					}
					st.pop();
				}
			}else{
				b[x]++;
				st.push(x);
			}
		}
		while(!st.empty()){
			int x=st.top();
			st.pop();
			c[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
} 

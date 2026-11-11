#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N];
int sum[N];
bool b[N];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				st.push(a[j]);
				b[a[j]]=1;
			}else{
				while(a[j]!=st.top()){
					int c=st.top();
					b[c]=0;
					st.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]) sum[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}

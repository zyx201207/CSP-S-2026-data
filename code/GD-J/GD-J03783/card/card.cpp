#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;

int n,m,a[N],ans[M];
bool b[M];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){b[a[j]]=1;st.push(a[j]);}
			else{
				while(b[a[j]]){
					int x=st.top();
					b[x]=0;
					st.pop();
				}
				st.push(a[j]);b[a[j]]=1;
			}
		}
		while(!st.empty()){
			int x=st.top();
			st.pop();
			ans[x]++;b[x]=0;
		}
	}
	for(int i=1;i<=m;i++){cout<<ans[i]<<' ';}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

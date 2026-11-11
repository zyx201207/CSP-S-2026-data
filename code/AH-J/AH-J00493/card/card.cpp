#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,op[300005],bk[300005];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		memset(bk,0,sizeof(bk));
		for(int j=i;j<=n;j++){
			if(st.empty()){
				st.push(a[j]);
				bk[a[j]]++;
			}else{
				if(bk[a[j]]){
					while(st.top()!=a[j]){
						bk[st.top()]--;
						st.pop();
					}
					st.pop();
					st.push(a[j]);
				}else{
					st.push(a[j]);
					bk[a[j]]++;
				}
			}
		}
		while(!st.empty()){
			op[st.top()]++;
			st.pop();
		}
	}
	op[a[n]]++;
	for(int i=1;i<=m;i++)cout<<op[i]<<" ";
	return 0;
}

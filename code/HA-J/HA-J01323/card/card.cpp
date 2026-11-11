#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],b[N],ans,n,m,c[N];
stack <int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,-1,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==-1){
				b[a[j]]=i;
				st.push(a[j]);
			}else{
				while(1){
					if(st.top()==a[j]){
						break;
					}else{
						b[st.top()]=-1;
						st.pop();
					}
				}
			}
		}
		while(st.size()) st.pop();
		for(int j=1;j<=m;j++){
			if(b[j]!=-1) c[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

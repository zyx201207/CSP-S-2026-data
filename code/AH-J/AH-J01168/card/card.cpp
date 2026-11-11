#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=3e5+5;
LL n,m,b[N],a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		stack<LL>st;
		while(!st.empty()){st.pop();}
		for(int j=i;j<=n;j++){
			if(st.empty()) st.push(a[j]);
			else{
				stack<LL>ss;LL ok=1;
				while(!ss.empty()){ss.pop();}
				while(!st.empty()){
					LL k=st.top();
					if(k==a[j]){ok=0;break;}
					ss.push(st.top());
					st.pop();
				}if(ok==1){
					while(!ss.empty()){
						st.push(ss.top());
						ss.pop();
					}st.push(a[j]);
				}
			}
		}while(!st.empty()){
			b[st.top()]++;st.pop();
		}
	}for(int i=1;i<=m;i++) cout<<b[i]<<" ";
    return 0;
}

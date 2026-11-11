#include <bits/stdc++.h>
using namespace std;
int a[500005];
int pot[300005];
int ans[300005];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!pot[a[j]]){
				pot[a[j]]=1;
				st.push(a[j]);
			}
			else{
				while(st.top()!=a[j]){
				    pot[st.top()]=0;
					st.pop();
				}
			}
		}
		for(int j=1;j<=maxn;j++){
			if(pot[j]) ans[pot[j]]++;
		}
		while(st.size()) st.pop();
	}
	for(int i=1;i<=maxn;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
//I don't know what is"segmentation fault" amd why will it appear in my T4 output.

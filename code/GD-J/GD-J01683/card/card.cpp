#include<bits/stdc++.h>
using namespace std;
struct S{
	int x,a;
};
int n,m;
int a[500007];
int t[300007];
stack<S> st;
int e[300007],s[300007];
int z[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z[a[i]]=i;
	}
	for(int i=n,j=n;i>=1;i--){
		if(t[a[i]]!=0){
			int x=a[i];
			while(st.top().a!=x){
				S u=st.top();
				if(u.x=z[u.a]) e[st.top().a]++;
			}
		}
	    st.push({i,a[i]});
		t[a[i]]++;
		if(t[a[i]]==1)	s[a[i]]=i;
	}
		for(int i=1;i<=m;i++){
		cout<<s[i]-e[i]<<" ";
	    }
	   return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],f[300010],s[300010];
stack<long long> st;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=0){
				while(st.top()!=a[j]){
					f[st.top()]--;
					st.pop();
				}
			}
			else{
				st.push(a[j]);
				f[a[j]]++;
			}
		}
		memset(f,0,sizeof(f));
		while(!st.empty()){
			//cout<<st.top()<<" ";
			s[st.top()]++;
			st.pop();
		}
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}

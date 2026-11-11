#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[300005];
stack<long long> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long b[300005];
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				for(int k=b[a[j]];k<=j;k++){
					st.pop();
				}
			}
			st.push(a[j]);
			b[a[j]]=j;
		}
		while(!st.empty()){
			c[st.top()]++;
			st.pop();
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],b[500009],tong[300009];
stack<long long>st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=st.size();k++){
				while(a[j]!=st.top()){
					st.pop();
				}
			}
			st.push(a[j]);
		}
		for(int j=1;j<=st.size();j++){
			tong[st.top()]++;
			st.pop();
		}
		for(int j=1;j<=m;j++){
			cout<<tong[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

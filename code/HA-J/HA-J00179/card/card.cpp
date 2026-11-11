#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
stack<int> st;
int n,m,a[N],t[N],tmp[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++)
		{
			if (!tmp[a[j]]){
				tmp[a[j]]++;
				st.push(a[j]);
			}
			else {
				while(st.top()!=a[j]){
					tmp[st.top()]--;
					st.pop();
				}
			}
		}
		while(!st.empty())
		{
			t[st.top()]++;
			
			st.pop();
		}
		for (int j=0;j<n;j++) tmp[j]=0;
	}
	for (int i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
}

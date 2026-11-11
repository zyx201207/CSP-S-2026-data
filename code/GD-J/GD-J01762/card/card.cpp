#include<bits/stdc++.h>

using namespace std;

int n,m,a[500010];
int ans[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++){
		stack<int> st; 
		for(int j=i;j<=n;j++){
			int k;
			stack<int> sp=st;
			int ff[500010];
			for(int i=1;i<=m;i++){
				ff[i]=0;
			}
			while(sp.size())
			{
				int x=sp.top();
				cout << x << ' ';
				st.pop();
				ff[x]++;
			}
			st.push(a[j]);
		}
		int f[500010];
		for(int i=1;i<=m;i++){
			f[i]=0;
		}
		while(st.size())
		{
			int x=st.top();
			cout << x << ' ';
			st.pop();
			f[x]++;
		}
		for(int i=1;i<=m;i++){
			if(f[i]) ans[i]++;
		}
		cout << endl;
	}
	
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' '; 
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 

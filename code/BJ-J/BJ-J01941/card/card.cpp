#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(N),b(N,0),c,ans(N,0);
    string s="";
    vector<bool> x(N,0);
    for(int i=1;i<=n;i++) cin>>a[i],b[a[i]]++;
    for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1) x[j]=1,c.push_back(a[j]);
		}
		for(int j=1;j<=m;j++) if(x[j]) ans[j]++;
	}
	for(int j=1;j<=m;j++) cout<<ans[j]<<" ";
    fclose(stdin);
	fclose(stdout);
    return 0;
}




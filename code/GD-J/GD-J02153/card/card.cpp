#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> ans(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
    	vector<int> t(n+1,-1);
    	int r=0;
    	for(int j=i;j<=n;j++){
    		for(int k=1;k<=r;k++){
    			if(a[j]==t[k]){
    				r=k-1;
    				break;
				}
			}
			t[++r]=a[j];
		}
		for(int j=1;j<=r;j++) ans[t[j]]++;
	}
	for(int j=1;j<=m;j++) cout<<ans[j]<<" ";
}


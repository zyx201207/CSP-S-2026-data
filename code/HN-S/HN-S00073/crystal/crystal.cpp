#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[500005],f[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,maxx=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	f[1]=0;
	for(int i=2;i<=n;i++){
		f[i]=(long long)f[i-1]+(long long)(i-1)*(long long)(a[i]-a[i-1]);
		if(m>=f[i])maxx=i;
	} 
	cout<<maxx;
	return 0;
}
/*
                           ||||||||||
                         ||/       \||
                         |/         \|
                         |  --   --  |
                         |   R   R   |
                          \         /
                           \ \___/ /
                            -------
                             |   |
                     /-------------------\
					/   /|           |\  \
				   /   / |           | \  \
			   	   \   \ |           | /  /
					\   \|   _____   |/  /
					 \   \  /     \  /  / 
					 | __==|  / \  |==  |
					 | __==|  \ /  |==  |
					        \_____/ 
						                          */

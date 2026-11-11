#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N],t[N],ans[M],b[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1; i<=n; i++){
		for(int i=1; i<=n; i++) t[i]=0;
		for(int j=i; j<=n; j++){
			if(t[a[j]]==0) t[a[j]]=1;
			else{
				for(int k=i; k<j; k++)
					t[a[k]]=0;
				t[a[j]]=1;
			}
		}
		for(int j=i; j<=n; j++)
			if(t[a[j]]==1){
				ans[a[j]]++;
				t[a[j]]=0;
				//cout<<a[j]<<" ";
			}
		//cout<<endl;
	}
	//cout<<endl;
	for(int i=1; i<=m; i++)
		cout<<ans[i]<<" ";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N1=500500;
const int N2=500500;
int n,m;vector<int> v(N1);
int a[N1],b[N2];bool f[N1];
signed main()
{

	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>> n >> m;
	for (int i=1;i<=n;i++){
		cin>> a[i];
	}
	for (int i=1;i<=n;i++){
		int k=0;memset(f,0,sizeof(0));
		for (int j=i;j<=n;j++){
			if (!f[a[j]]){
				k++;f[a[j]]=true;
				v[k]=a[j];
			}else {
				while (v[k]!=a[j]){
					f[v[k]]=false;
					v[k]=0;k--;
				}
			}
		}
		for (int j=1;j<=m;j++){
			b[j]+=f[j];
		}
	}
	for (int i=1;i<=m;i++){
		cout<< b[i] << " ";
	}

return 0;
}


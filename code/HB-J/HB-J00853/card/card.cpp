#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=3e5+5;
int n,m,a[MAXN],t[MAXM];
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int id=1;id<=m;id++){
		memset(t,0,sizeof(t));
		int tt[MAXM];
		vector<int> v;
		for (int i=n-m;i<=n;i++){
			if (tt[a[i]]==1){
				bool flag=0;
				for (int j=0;j<v.size();j++){
					if (v[i]==0) continue;
					if (v[i]==a[i]) flag=1;
					if(flag) v[i]=0;
				}
			}
			v.push_back(a[i]);
			tt[a[i]]++;
		}
		for (int i=0;i<v.size();i++){
			t[v[i]]++;
		}	
	}
	for (int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}

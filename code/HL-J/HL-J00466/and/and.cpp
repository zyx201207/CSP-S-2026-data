#include <bits/stdc++.h>
using namespace std;
int n,m,ci=0,ma=0;
int a[200005];
bool b[200005];
int an(int x){
	for (int i=0;i<n;i++){
		if (ci==m){
			return x;
		}
		else if (b[i]==1){
			continue;
		}
		else{
			ci++;
			b[i]=1;
			return (an(x&a[i]));
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			b[i]=0;
		}
		ci++;
		int ann=an(a[i]);
		if(ann>ma){
			ma=ann;
		}
	}
	cout<<ma;
	return 0;
}

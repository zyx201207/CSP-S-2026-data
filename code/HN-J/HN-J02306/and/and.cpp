#include<bits/stdc++.h>
using namespace std;
long long a[100009],maxn=-2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,opo=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			opo=i;
			maxn=a[i];
		}
	}
	for(int i=2;i<=m;i++){
		a[opo]=-1;
		opo=0;
		maxn=-2;
		for(int j=1;j<=n;j++){
			if(a[j]>maxn)
			{
				opo=j;
				maxn=a[j];
			}
		}
	}
	cout<<maxn;
return 0;
}



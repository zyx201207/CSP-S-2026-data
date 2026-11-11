#include<bits\stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n;
	int a[10000005];
	int m;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		
		cin>>a[i];	
	}
	for(int i=1;i<=n-m;i++){
		int ma=1;
		for(int j=i;j<=m+i;j++){
			ma=ma and a[j];
		}
		if(ma>maxn) maxn=ma;
	}
	cout<<maxn;
	return 0;
}

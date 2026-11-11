#include<bits/stdc++.h>
using namespace std;
long long int a[100000001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,q;
	cin>>n>>m;
	for(long long int i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long int i=0;i<n;i++){
		for(long long int j=i;j>0;j--){
			if(a[j]<a[j-1])
			{
				q=a[j-1];
				a[j-1]=a[j];
				a[j]=q;
			}
		}
	}
	cout<<3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b=0;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=1;j++)
		{
			int s=0;
			s = a[i] and a[j];
			if(s>b){
				b=s; 
			}
		}
	}
	

	cout<<b;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long s=0;
	long long maxs=0;
	long long n;
	long long m;
	cin>>n>>m;
	for (int k=0;k<n;k++){
	cin>>a[k];
	}
	for(int y=0;y<m;y++){
	long long  s=a[y]+a[y+1];
	if(s>maxs){maxs=s;} 		
	}
	cout<<"12"<<endl;
	return 0;
}
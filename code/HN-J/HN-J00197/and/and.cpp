#include <bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	long long n,m;
	cin >> n >> m;
	long long max=0;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		if(a>max){
			max=a;
		}
	}
	cout<<max;
	return 0;
}

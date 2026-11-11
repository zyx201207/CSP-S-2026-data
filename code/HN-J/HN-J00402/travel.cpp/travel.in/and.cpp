#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n, m;
	cin>> n >> m;
	int x[n];
	for(int i=0; i<n; i++){
		cin >> x[i];
	}
	if(m==1){
		int y=-1;
		for(int i=0; i<n; i++){
			if(x[i]>y){
				y=x[i];
			}
		}
		cout << y;
	}
	return 0;
}

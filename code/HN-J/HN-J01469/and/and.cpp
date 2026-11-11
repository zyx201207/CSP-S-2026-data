#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	int max = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int b = 0;
		b = a[i] and a[i+1];
		if(b > max){
			max = b;
		}
	}
	cout << max;
	return 0;
}

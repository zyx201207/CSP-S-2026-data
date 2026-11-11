#include<bits/stdc++.h>
using namespace std;
int a[100000];
int c[1000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int s,b;
	cin >> b;
	for(int i = 0;i <= b;i++){
		cin >> c[i];
	}
	for(int i = 0;i<=b;i++){
		for(int j = b;j<=b;j--){
			if(a[i] != a[j]){
				s += 1;
			}
		}
	}
	cout << s;
	return 0;
}

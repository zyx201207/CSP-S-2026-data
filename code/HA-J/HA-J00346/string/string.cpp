#include<bits/stdc++.h>
using namespace std;
int n,a[1001];
char c[1001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> c[i];
	}
	if(n == 1)
	cout << 0;
	if(n == 2)
	{
		for(int i = 1;i <= n;i++){
			if(c[i] == c[i + 1]){
			cout << 0;
			return 0;
		}
			else{
			cout << min(a[i],a[i + 1]);
			return 0;
		}
		}
	}
	else
	cout << n - 1;
	return 0;
}

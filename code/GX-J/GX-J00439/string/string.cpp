#include <bits/stdc++.h>
using namespace std;
void re(string a)
{
	int num = 0;
	for(int i = 0,j = a.size()-1;i < a.size();i++,j--){
		if(a[i] !=a[j]){
			a[j] = a[i];
			num++;
		}
	}
	return num;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string p;
	int n;
	cin >> n;
	for(int i = 0;i <= n;i++){
		string q;
		cin >> q;
		p += q;
	}
	cout << re(p);
	return 0;
}

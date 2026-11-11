#include <bits/stdc++.h>
using namespace std;
long long ran,num;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> ran >> num;
	vector <long long> list(ran);
	for (long long i = 0;i < ran;i++) cin >> list[i];
	sort(list,list + num);
	long long out = list[0];
	for (long long i = 1;i < num;i++) out = out && list[i];
	cout << out;
	return 0;
}

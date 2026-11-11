#include <bits/stdc++.h>
using namespace std;
long long ran,letter_num,cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string str;
	char letter;
	cin >> ran;
	vector <long long> num_list(ran);
	vector <char> letter_list(ran);
	for (long long i = 0;i < ran;i++)
	{
		cin >> letter_num >> letter;
		num_list[i] = letter_num;
		letter_list[i] = letter;
	}
	for (long long i = 0;i < ran;i++)
        for (long long j = 0;j < num_list[i];j++) str += letter_list[i];
	for (long long i = 0;i < str.length() / 2;i++) cnt += (str[i] != str[str.length() - 1 - i]);
	cout << cnt;
	return 0;
}

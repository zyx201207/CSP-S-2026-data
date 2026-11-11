#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int ans = 0, question_count;
	string S;
	string a, b, c;
	cin >> question_count;
	for (int i = 1; i <= question_count; i++)
	{
		int letter_count;
		char now_letter;
		cin >> letter_count >> now_letter;
		if (now_letter == 'a')
		{
			for (int i = 1; i <= letter_count; i++)
			{
				a += 'a';
			}
		}
		else if (now_letter == 'b')
		{
			for (int i = 1; i <= letter_count; i++)
			{
				b += 'b';
			}
		}
		else
		{
			for (int i = 1; i <= letter_count; i++)
			{
				c += 'c';
			}
		}
	}
	S += a;
	S += b;
	S += c;
	int S_size = S.size();
	for (int i = 0; i < (S_size / 2); i++)
	{
		if (S[i] != S[S_size - i - 1])
		{
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
} 

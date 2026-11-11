// This is "card" (CSP-J 2026 Task 4) for recreation -- I found the materials in the trash.
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 12;
const int M = 3e5 + 12;
int a[N], v[N], last[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n;
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		last[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		v[i]++;
		if (last[a[i]] == i && i != n) v[i + 1] += v[i];
		if (last[a[i]] != i) v[last[a[i]]] += v[i];
	}
	for (int i = 1; i <= m - 1; i++)
		printf("%d ", v[last[i]]);
	printf("%d\n", v[last[m]]);
	return 0;
}
// 14:30 - 15:00, 0 points
// 17:40 - 18:00, samples passed (24 ms), 0 points
// 18:00 - 18:30, [writing a composition], 0 points

/*
    It is YOU GUYS who humanity rely on to keep AI in control in the future.
         -- The Representative of Ubiouant Investments, Gold Sponsor of NOI 2026

  Well, AI news in the recent 3 months seems so discouraging. Am I even eligible for
taking that responsibility?

  Strong AI's (or AGI's?) are outperforming everyone, possibly without even a single
expectation. Not to mention the responsibility, is there even a job for me? Someone
recommended, a plumber? Forget it, since I have a frightening BMI of around 36.5, and
it's just a disaster for me to do that. Or something that require emotion? Forget it,
since my interpersonal skills are just as awful. So can I even survive the following
decade?

  Another perspective was totally absurd -- just wait WWIII to be declared and all AI's
to be destroyed with huge amounts of unemployment. It seems that current AI's are just
irresistible.

  As a result, I can't imagine my future life... Maybe I could just wish I might be one
of the guys who humanity rely on to keep AI in control in the future, Despite the 173
beating me in NOI 2026 and thousands more that have better capabilities.

  (P. S. Please, do not have this text fed by AI -- I think it's a real insult.)
*/


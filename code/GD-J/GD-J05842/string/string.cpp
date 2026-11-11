#include<bits/stdc++.h>
int a[200005] = {0};
char s[100000005] = {'\0'};
char t[200005] = {'\0'};
int main()
{
	std::freopen(&"string.in"[0],&"r"[0],stdin);
	std::freopen(&"string.out"[0],&"w"[0],stdout);
	long long n = 0LL;
    std::scanf(&"%lld"[0],&n);
    long long mx = 0LL;
    for(int i = 1;i <= n;i = i + 1)
    {
        std::scanf(&"%d %c"[0],&a[i],&t[i]);
        mx = std::max<long long> (mx,(long long)(a[i]));
    }
    if(n * mx > 100000000LL)
    {
        return 0;
    }
    int j = 0;
    for(int i = 1;i <= n;i = i + 1)
    {
		for(int k = 1;k <= a[i];k = k + 1)
		{
			s[j + k] = t[i];
		}
		j = j + a[i];
    }
	int cnt = 0;
	for(int i = 1;i <= j / 2;i = i + 1)
	{
		if(s[i] != s[j - i + 1])
		{
			cnt = cnt + 1;
		}
	}
	std::printf(&"%d"[0],cnt);
	return 0;
}

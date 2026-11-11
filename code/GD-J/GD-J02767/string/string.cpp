#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int eps = 1e-12;
const int N = 2e5 + 20;
/*
思路1(模拟)(预估得分40)
将对应的数字个数等比例缩小，答案等比例放大
超时 
思路2(预估得分100)
算出字符串总长度
判断前字符串和后字符串的位置答案 
要特别注意最中间的段有可能属于前后两段
最后用对拍进行比较验证答案 
*/
int n;
int a[N];//数字个数 
char c[N];//字符 
char last_q ,last_h; 
ll cnt = 0;//答案 
ll lens = 0;
ll qlens = 0, hlens = 0;//前后字符串已算的长度 
ll qz, hz;//qz表示前字符串比对时剩下的字符,hz表示后字符串比对时剩下的字符
//正常情况下,必定有一方为0 
int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
//	cout.tie (0);
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> c[i];
		lens += a[i];
	}
	
	ll palf_lens_q = lens / 2;
	//应该还要注意奇偶回文的区别
	int head = 1, tail = n; // 头尾指针 
	while (qlens + hlens < lens && head <= tail && head <= n && tail >= 1 && qlens < palf_lens_q && hlens < palf_lens_q)
	{
		// last_q表示上一个前字符串字符
		// last_h表示上一个后字符串字符
		// qz表示上一个前字符个数
		// hz表示上一个后字符个数 
		// new_q表示现在前字符串字符
		// new_h表示现在后字符串字符
		// new_qx表示现在前字符的个数
		// new_hx表示现在后字符的个数 
		char new_q = c[head], new_h = c[tail];//前后字符 
		int new_qx = 0, new_hx = 0;
		
		//旧新字符对比 
		if (hz == 0)
		{
			if (qlens + a[head] <= palf_lens_q) new_qx = a[head], qlens += a[head], ++head;//如果没到终点,直接加 
			else if (qlens == palf_lens_q) new_qx = 0; //如果在终点,不改变 
			else new_qx = palf_lens_q - qlens, qlens = palf_lens_q;//如果要到终点,直接到终点 
		}
		while (hz != 0)
		{
			new_q = c[head];
			if (qlens + a[head] <= palf_lens_q) new_qx = a[head], qlens += a[head], ++head;//如果没到终点,直接加 
			else if (qlens == palf_lens_q) new_qx = 0; //如果在终点,不改变 
			else new_qx = palf_lens_q - qlens, qlens = palf_lens_q;//如果要到终点,直接到终点 
			if (last_h != new_q)
			{
				if (hz > new_qx)
				{
					cnt += new_qx;
					hz -= new_qx;
					qz = 0;
					new_qx = 0;
					last_q = new_q;
				}else{
					cnt += hz;
					new_qx = new_qx - hz;
					hz = 0;
				}
			}else{
				if (hz > new_qx) 
				{
					hz -= new_qx;
					new_qx = 0;
					last_q = new_q;
				}else{
					new_qx -= hz;
					hz = 0;
				}
			}
		}
		if (qz == 0)
		{
			if (hlens + a[tail] <= palf_lens_q) new_hx = a[tail], hlens += a[tail], --tail;
			else if (hlens == palf_lens_q) new_hx = 0;
			else new_hx = palf_lens_q - hlens, hlens = palf_lens_q;	
		}
		while (qz != 0)
		{
			new_h = c[tail];
			if (hlens + a[tail] <= palf_lens_q) new_hx = a[tail], hlens += a[tail], --tail;
			else if (hlens == palf_lens_q) new_hx = 0;
			else new_hx = palf_lens_q - hlens, hlens = palf_lens_q;	
			if (last_q != new_h)
			{
				if (qz > new_hx)
				{
					cnt += new_hx;
					qz -= new_hx;
					new_hx = 0;
					last_h = new_h;
				}else{
					cnt += qz;
					qz = 0;
				}
			}else{
				if (qz > new_hx) 
				{
					qz -= new_hx;
					new_hx = 0;
					last_h = new_h;
				}else{
					new_hx = new_hx - qz;
					qz = 0;
				}
			}
		}
		//新的字符对比 
		if (new_q != new_h)
		{
			if (new_qx > new_hx)
			{
				cnt += new_hx;
				qz = new_qx - new_hx;
				hz = 0;
				last_q = new_q;
				last_h = new_h;
			}else{
				cnt += new_qx;
				hz = new_hx - new_qx;
				qz = 0;
				last_q = new_q;
				last_h = new_h;
			}
		}else{
			if (new_qx > new_hx)
			{
				qz = new_qx - new_hx;
				hz = 0;
				last_q = new_q;
				last_h = new_h;
			}else{
				hz = new_hx - new_qx;
				qz = 0;
				last_q = new_q;
				last_h = new_h;
			}
		}
	} 
	cout << cnt;
	return 0;
}


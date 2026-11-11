#include<bits/stdc++.h>

using namespace std;

constexpr int MAX = 5 * 1e5 + 10;
int a[MAX], cnt[MAX], nowdesk[MAX], n, m, deskright = 1;
int nowput[MAX];        //编号为i的数字在桌面上的位置 

void put(int num)
{
	if(nowput[num] == 0)
	{
		nowput[num] = deskright;
		nowdesk[deskright ++] = num;
		//deskright总是指向第一个空位
		return; 
	}
	else
	{
		for(int i = nowput[num] + 1; i <= deskright; i++)
		{
			nowput[nowdesk[i]] = 0;    //右侧是nowdesk[i]， 通过“nowput[nowdesk[i]] = 0”讲数字标记为“未使用”，即清空 
			nowdesk[i] = 0;            //清空右侧 
		}
		deskright = nowput[num] + 1;    //deskright总是指向第一个空位
		return;
	}
}

void erase()
{
	memset(nowdesk, 0, sizeof(nowdesk));//清空桌面，防止干扰
	memset(nowput, 0, sizeof(nowput));  //清空已放 
	deskright = 1;                      //清空右侧位置 
}

int main()
{
 	freopen("card.in", "r", stdin);
 	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	//暴力 
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)	
	{
		erase();    //清空 
		for(int j = i; j <= n; j++)
		{
			put(a[j]);
		}
		for(int j = 1; j <= m; j++)
		{
			cnt[j] += (bool)(nowput[j]);    //统计 
		}
	}
	
	for(int i = 1; i <= m; i++)
	{
		cout << cnt[i] << ' ';
	}
	
	return 0;
}


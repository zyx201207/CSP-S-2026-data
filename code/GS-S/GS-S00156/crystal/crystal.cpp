//#include<bits/stdc++.h>
//using namespace std;
//long long N[500005];
//int M[500005];
//vector<int> V;
//int n,m;
//int solve(int n)
//{
//	int cnt = 0;
//	int _m = m;
//	for(int i = n - 1;i >= 0;i--)
//	{
//		if(n - i > _m) break;
//		if(M[i] == 0) continue;
//		int temp = _m / (n - i);
//		if(temp >= M[i])
//		{
//			cnt += M[i];
//			_m -= M[i] * (n - i);
//		}
//		else
//		{
//			cnt += temp;
//			_m -= temp * (n - i);
//			break;
//		}
//	}
//	return cnt;
//}
//int main()
//{
//	freopen("crystal2.in","r",stdin);
//	freopen("Out.out","w",stdout);
//	cin>>n>>m;
//	cout<<3;
//	long long maxnum = INT_MIN;
//	for(int i = 1;i <= n;i++)
//	{
//		cout<<4;
//		cin>>N[i];
//		maxnum = max(maxnum,N[i]);
//		if(M[N[i]] == 0)
//		{
//			V.push_back(N[i]);
//		}
//		M[N[i]]++;
//		cout<<1;
//	}
//	sort(V.begin(),V.end());
//	int max_ans = INT_MIN;
//	for(int i = 1;i <= maxnum;i++)
//	{
//		max_ans = max(max_ans,solve(i) + M[i]);
//		cout<<2;
//	}
//	cout<<max_ans;
//}

#include<bits/stdc++.h>
using namespace std;
long long N[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out ","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long max_ans = -10;
	for(long long i = 1;i <= n;i++)
	{
		cin>>N[i];
	}
	sort(N + 1,N + n + 1);
	long long cnt = 0;
	long long head = 1,tail = 1;
	for(long long i = 1;i <= n;i++)
	{
		while(N[head] <= i)
		{
			cnt += N[head];
			head++;
		}
		while((head - tail) * i - cnt > m)
		{
			cnt -= N[tail];
			tail++;
		}
		max_ans = max(max_ans,(head - tail));
	}
	cout<<max_ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

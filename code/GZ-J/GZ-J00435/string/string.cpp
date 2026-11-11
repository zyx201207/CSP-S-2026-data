#include<bits/stdc++.h>//李政轩 GZ-J00435 
using namespace std;
const int maxn = 1e6+325;
long long n,sum;
struct Zc{
	long long num;
	char word;
}a[maxn];
string s,s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i = 1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].word;//输入
		for(long long j = 1;j<=a[i].num;j++)//建设字符串(需改) 
		{
			s+=a[i].word;
		}
		s1+=a[i].word;
	}
	long long l = s.size();
	for(long long i = 0;i<(l+1)/2;i++)
	{
		if(s[i]!=s[l-1-i])sum++;
	}
	cout<<sum;
	return 0;
} 
//思路：将结构体a自己比较
//若a[i].word!=a[n+1-i].word,那么我们比较 n+1-i与i大小
//如果n+1-i>i,那sum+=
//数字要先回文

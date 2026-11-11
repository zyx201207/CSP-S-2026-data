#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],len,coco,charlie;
char s[200005];
string zs;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++)	
	{
		cin >> a[i] >> s[i];
		len += a[i];
	}
	for(long long i = 1;i <= len;i++)
	{
		for(long long j = 1;j <= a[i];j++)	zs[++coco] = s[i];
	}
	for(int i = 1;i <= len/2;i++)
	{
		if(zs[i] != zs[len-i])	charlie++;
	}
	if(n == 1)	cout << "0";
	else	cout << charlie;
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],len,charlie,qzh[200005],coco = 1,nono = n;
char s[200005];
string zs;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++)	
	{
		cin >> a[i] >> s[i];
		len += a[i];
		qzh[i] = qzh[i-1]+a[i];
	}
	for(long long i = 1;i <= len/2;i++)
	{
		if(i > qzh[coco-1]&&i > qzh[coco])	coco = coco;
		else	coco++;
		if(len-i+1 > qzh[nono-1]&&len-i+1 < qzh[nono])	nono = nono;
		else	nono--;
		if(s[coco] == s[nono])	charlie++;
	}
	cout << charlie;
	return 0;
}
*/


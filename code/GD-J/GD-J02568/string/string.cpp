#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 200010;

int n;
LL a[N]; char s[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++){
		cin>>a[i]>>s[i];
	}
	int i = 1,j = n;
	LL c1 = a[1],c2 = a[n],ans = 0;
	char s1 = s[1],s2 = s[n];
	while (i <= j)
	{
		if (s1 == s2){
			if (c1 > c2){
				c1 -= c2;
				j--;
				c2 = a[j],s2 = s[j];
			}
			else{
				c2 -= c1;
				i++;
				c1 = a[i],s1 = s[i];
			}
		}
		else{
			if (c1 > c2){
				ans += c2;
				c1 -= c2;
				c2 = 0;
				j--;
				c2 = a[j],s2 = s[j];
			}
			else{
				ans += c1;
				c2 -= c1;
				i++;
				c1 = a[i],s1 = s[i];
			}
		}
	}
	cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long k,sum;
unsigned long long h;
string at;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char a,b;
	bool flag=1;
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> k;
		h+=k;
		cin >> a;
		for(int i = 1;i<=k;i++)at=at+a;
		if (a!=b&&i>1)flag=0;
		else b=a;	
	}
	int le=0,ri=h-1;
	for(int i = 0;i<h;i++){
		if(le<=ri){
			if(at[le]!=at[ri])sum+=1;
		}
		le++;
		ri--;	
	}
	if(flag)cout << 0;
	else cout << sum;
	return 0;
}

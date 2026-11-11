#include<bits/stdc++.h>
using namespace std;

long long n,m;
int num[500005], a[50005];

int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		if(i > 1)
		{
			a[i] = num[i] - num[i-1];
		}
	}
	sort(num,num+n);
    int flag = 0;
	while(m && flag < n)
	{
		if(a[flag] == 0) flag++;
		else{
			a[flag]--;
			m--;
		}
	}
	cout << (flag-1);
	return 0;
}



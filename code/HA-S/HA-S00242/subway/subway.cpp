#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],pfx[500005];
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = n - 1;i >= 1;i--){
		pfx[i] = a[i]+pfx[i + 1];
	}
//	for (int i = 1;i < n;i++)cout << pfx[i] << " ";
	int cnt = 1,maxans = 0;
	for (int i = n,j = n;i >= 1;i--){
		
		if(pfx[j]*(j - i)-(pfx[i] - pfx[j]) <= m){
			i--,cnt++;
		}if(cnt > maxans)maxans = cnt;
		else{
			if(j + 1 <= i)j--,cnt--;
		}
	}
	cout << maxans;
	return 0;
}

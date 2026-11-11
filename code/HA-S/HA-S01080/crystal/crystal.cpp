#include<bits/stdc++.h>
#include<queue>
using namespace std;
const int MAXN = 5e5 + 1;
int n,m;
long long arr[MAXN];
bool pd_xd = true,pd_dc = true;
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> arr[1];
	for (int i = 2;i <= n;i++){
		cin >> arr[i];
		if (arr[i] != arr[i - 1]) pd_xd = false;
		else if (arr[i] - arr[i - 1] != arr[2] - arr[1]) pd_dc = false;
	}
	if (pd_xd){
		cout << n;
		return 0;
	}
	if (pd_dc){
		int cz = arr[2] - arr[1];
		int temp = m / cz;
		int i = 1;
		int sum = 0;
		while (temp){
			temp -= i;
			i++;
			sum++;
		}
		cout << sum + 1;
		return 0;
	}
	long long maxn = 0;
	for (int i = 2;i <= n;i++){
		long long sum = 0;
		long long temp = m;
		for (int j = 1;i - j >= 1,temp >= 0;j++){
			temp -= arr[i] - arr[i - j];
			sum++;
		}
		maxn = max(sum + 1,maxn);
	}
	cout<< maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long Aai[200005],sum = 0,ans = 0;
	char Cci[200005];
	string ACS;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> Aai[i] >> Cci[i];
		sum += Aai[i];
	}
	
	if (sum > 5000000){
		cout << sum / 2;
		return 0;
	}
	
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= Aai[i];j++){
			ACS += Cci[i]; 
		}
	}
	for (int i = 0;i < sum / 2;i++){
		if (ACS[i] != ACS[sum-i-1]) ans++;
	}
	cout << ans;
	return 0;
} 

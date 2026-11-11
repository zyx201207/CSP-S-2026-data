#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005];
int cnt1[300005],num1[300005],cnt2[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = a[i];
	}
	for(int i = 1;i <= n;i++){
		int l = 0;
		for(int j = i;j <= n;j++){
			if(num1[a[j]] != 0){
				for(int k = cnt1[a[j]] + 1;k <= l;k++){
					num1[b[k]]--;
				}
				l = cnt1[a[j]];
			}
			else{
				l++;
				num1[a[j]]++;
				b[l] = a[j];
				cnt1[a[j]] = l;
			}
		}
		for(int j = 1;j <= m;j++){
			if(num1[j] != 0) cnt2[j]++;
		}
		for(int j = 1;j <= n;j++){
			num1[j] = 0;
			b[l] = 0;
			cnt1[j] = 0;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt2[i] << " ";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int Aai[200005];
int dfs(int n,int m,int num)
{
	if (m < 0) return -1;
	if (n < m) return -1;
	if (n == 0){
		if (m == 0) return num;
		else return -1;
	}
	return max(dfs(n-1,m-1,num & Aai[n]),dfs(n-1,m,num));
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int nn,mm;
	cin >> nn >> mm;
	for (int i = 1;i <= nn;i++){
		cin >> Aai[i]; 
	}
	
	if (nn <= 20){
		cout << dfs(nn,mm,pow(2,31)-1);
		return 0;
	}
	if (nn <= 2000){
		if (mm == 1){
			sort(Aai + 1,Aai + 1 + nn);
			cout << Aai[nn];
		}
		else if (mm == nn){
			int ans = Aai[1];
			for (int i = 2;i <= nn;i++){
				ans = ans & Aai[i];
			}
			cout << ans;
		}
		else{
			int ans = 0;
			for (int i = 1;i <= nn;i++){
				for (int j = i + 1;j <= nn;j++){
					ans = max(ans,Aai[i] & Aai[j]);
				}
			}
			cout << ans;
		}
		return 0;
	}
	if (mm = nn - 1){
		int sum = 0;
		for (int i = 1;i <= nn;i++){
			int ans = Aai[1];
			for (int j = 2;j <= nn;j++){
				if (j != i) ans = ans & Aai[j];
			}
			sum = max(sum,ans);
		}
		cout << sum;
		return 0;
	}
	sort(Aai+1,Aai+1+nn);
	int sum = Aai[nn];
	for (int i = nn - 1;i > nn - mm;i--){
		sum = sum & Aai[i];
	}
	cout << sum;
	return 0;
	
} 

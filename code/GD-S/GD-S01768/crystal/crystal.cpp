#include <bits/stdc++.h>
using namespace std;
long long n, m, maxx=-1, sum = 1, p1=0,p2=0;
long long a[100005];//a[i]<=10^12
int cmp(int x,int y){
	return x < y;
}//QwQ
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] != i) p1 = 1;
	}
	sort(a+1,a+n+1,cmp);
	for (int i = 2;i < n;i++){
		if (a[i]-a[i-1] != a[i+1]-a[i]){
			p2 = 1;
		}
	}
	if (p1==0){
		long long ans=1;
		long long cnt =1;
        while(m > 0){
        	if (m >= cnt){
        		m-=cnt;
        		ans++;
			}
			else{
				m=0;
			}
        	cnt++;
		}
		if (ans > n){
			ans=n;
		}
		cout << ans;
		return 0;
	}
	if (p2==0){
		long long ans = 1;
		int lp=a[2]-a[1];
		long long cnt = lp;
		while (m > 0){
			if (m >= cnt){
        		m-=cnt;
        		ans++;
			}
			else{
				m=0;
			}
        	cnt+=lp;
		}
	    if (ans > n){
			ans=n;
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for (int i = 1;i <= n;i++){
		sum=1;
		for (int j = i-1;j > 0;j--){
			if(m >= a[i]-a[j]){
				m -= (a[i] - a[j]);
				sum++;
			}
		}
		maxx = max(maxx, sum);
	}
	cout << maxx;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

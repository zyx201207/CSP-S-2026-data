#include <bits/stdc++.h>
using namespace std;

long long n,m;

bool cmp(int a,int b){
	return 1;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	long long a[n+5]={};
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	int maxn=0;
	if (m==1){
		maxn = a[0];
		for (int i=1;i<n;i++){
			if (a[i] > maxn){
				maxn = a[i];
			}
		}
		cout << maxn;
		return 0;
	}
	if (m==n){
		int num=a[0];
		for (int i=1;i<n;i++){
			num = a[i] & num;
		} 
		cout << num;
		return 0;
	}
	if (m==2){
		maxn = a[0];
		int num=0;
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				num = a[i] & a[j];
				if (num > maxn){
					maxn = num;
				}
			}
		}
		cout << maxn;
		return 0;
	}
	if (m==n-1){
		sort(a,a+n,cmp);
		maxn = a[0];
		for (int i=1;i<n-1;i++){
			maxn = a[i] & maxn;
		}
		cout << maxn;
		return 0;
	}
	long long b[n]={};
	long long f=0;
	if (a[0] == 0){
//		maxn = a[0];
//		for (int i=1;i<n-1;i++){
//			maxn = a[i] & maxn;
//		}
//		cout << maxn;
//		return 0;
		
		for (int i;i<n;i++){
			if (pow(2,i) <= n){
				b[i] == pow(2,i); 
				f += 1;
			}
			m -= f;
			if (m = 0){
				cout << b[f-1];
			}else if (m < 0){
				f += m;
				cout << b[f-1]; 
			}
		}
	}else{
		sort(a,a+n,cmp);
		cout << a[0];
	}

	return 0; 
}

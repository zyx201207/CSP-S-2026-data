#include <bits/stdc++.h>
using namespace std;
long long arr[200100],res;
long long s[200100][40];


int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> arr[i];
		long long t=arr[i];

		for (int j=32;j>=1;j--){
			
			s[i][j]=t%2;
			t/=2;
		}
		
	}

	
	int cnt=0;
	for (int i=32;i>=1;i--){
		cnt=0;
		for (int j=1;j<=n;j++){
			if (s[j][i] == 1){
				swap(s[cnt],s[j]);
				
				cnt++;
			}
		}
		if (cnt > m) n=cnt;
		else break;
		
	}
	for (int i=1;i<=8;i++){
		for (int j=1;j<=32;j++){
			cout << s[i][j];
		}
		cout << endl;
	}
	
	int qz=1;
	for (int i=32;i>=1;i--){
		int x=1;
		for (int j=1;j<=m;j++){
			x&=s[j][i];
			
		}
		res+=qz*x;
		qz*=2;
	}
	cout << res;
	return 0;
} 

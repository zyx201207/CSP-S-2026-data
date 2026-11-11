#include <bits/stdc++.h>


#define ll long long

using namespace std;

const int N = 2e5 + 10;

bool cmp(int x,int y){
	return x>y;
}

int a[N];


int main()
{
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a + 1, a+ n + 1,cmp);
	int cnt =a[1];
	
	for(int i = 2;i<=m;i++){
		cnt &= a[i];
	}
	
	cout << cnt;
	
	
	
	
	
	return 0;
	
	
}
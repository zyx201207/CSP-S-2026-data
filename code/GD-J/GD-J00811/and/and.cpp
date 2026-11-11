#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define endl '\n' 
const int M=2e5+67;
int n,m;
int a[M];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
		
	sort(a+1,a+n+1,cmp);
		
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


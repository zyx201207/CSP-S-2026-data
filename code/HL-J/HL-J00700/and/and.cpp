#include<bits/stdc++.h>

using namespace std;
int n,m,t,a[1000000];
string s[1000000];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		sort(a,a+n+1);
		cout << a[n];
	}
	return 0;
}
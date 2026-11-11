#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
long long f[N];
long long v[N];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> v[i];
	}
	memset(f,-0x3f,sizeof(f));
	f[0] = 0;
	for(int i = 1;i <= n;i++){
		f[0] = v[i];
		for(int j = m;j >= 1;j--){
			f[j] = max(f[j],f[j-1]&v[i]);
		}
	}
	cout << f[m];
	return 0;
}


//GZ-J00092 马熙程 贵阳市南明区华麟学校
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
char b[105];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string k,k1;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cin >> b[i];
		for(int j = 1;j <= i;j++){
			k+=b[j];
		}
	}
	for(int i=n;i>=1;i--){
		k1+=b[i];
	}
	if(k!=k1){
		
	}else{
		cout << 0;
	}
	return 0;
} 

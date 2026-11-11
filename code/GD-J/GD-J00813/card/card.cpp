#include <bits/stdc++.h>
using namespace std;
struct a{
	string c;
}a[300005];
int b[300005],n,m;
string p;
string cmp(string x){
	
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= m;i++){
		cin >> a[i].c;
	}
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			cmp(a[i].c);
			p += a[i].c;
			
		}
	}
	for (int i = 1;i <= m;i++){
		cout << i << " ";
	}
	return 0;
}

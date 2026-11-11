//GZ-J00408 遵义市第十二中学 周子骞 
#include<bits/stdc++.h> 
using namespace std;
struct{
	long long num;
	string s;
}a[10000001];
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
int main(){
	int n , q = 0 , h = 0;
	string l;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].num >> a[i].s;
	}
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= a[i].num ; j++){
			l += a[i].s;
		}	
	}
	for(int i = 1; i <= ((l.size() - 1) / 2) + 1 ; i++){
		if(a[i].s == a[i + 1].s) q += 1;
	}
	for(int i = ((l.size() - 1) / 2) + 2; i <= l.size() ; i++){
		if(a[i].s == a[i + 1].s) h += 1;
	}
	if(h == 0 && q == 0) cout << "0";
	else cout << l.size() - h - q - 1;
	return 0;
}

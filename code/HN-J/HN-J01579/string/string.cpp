#include<bits/stdc++.h>
using namespace std;
int n,a,cs = 0;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string z;
	for(int i = 1;i <= n;i++){
		cin >> a >> c;
		cs += a;
		for(int j = 1;j <= a;j++){
			z += c;
		}
	}
	int l = 1,r = cs;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(l >= r){
			break;
		}
		else{
			if(z[l] != z[r]){
				z[l] = z[r];
				ans++;
			}
		}
		l+=1,r-=1;
	}
	cout << ans;
	return 0;
}

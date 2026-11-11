//GZ-S00348¿ÓÍª—Ù 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n = 0;
	long long m = 0;
	cin>>n>>m;
	long long a[10001] = {0};
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long b[10001] = {0};
	for(int i = 0;i < n;i++){
		int z = 0;
		int zyxb = 0;
		for(int j = i-1;j >= 0;j--){
			z += a[i] - a[j];
			zyxb = i+1;
		}
		if(z == m){
			int s = 0;
			for(int h = 0;h < n;h++){
				if(a[zyxb] == a[h] && h != zyxb){
					s++;
				}
			}
			cout<<zyxb+s;
			break;
		}
	}
	return 0;
}

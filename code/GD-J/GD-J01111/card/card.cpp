#include<bits/stdc++.h>
using namespace std;
long long ans[300010];
long long n,m,r;
long long a[500010],s[500010];
int main(){
//	freopen("card.in","r",stdin);
//	freoprn("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	r = 1;
	for(int i = 1;i <= n;i++){
		int cnt = 0;
		for(int i = 1;j <= n;j++){
			int d = a[j];
			for(int x = 1;x <= r;x++){
				if(s[x] == d){
					
				}		
			}
		} 
	} 
	return 0;
}

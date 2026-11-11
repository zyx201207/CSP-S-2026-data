#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long v[500005];
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	int n,m,cnt = 0;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	if(n == m){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(i == a[j]) cout<<j<<' ';
			}
		}
		return 0;
	}
	int cnt1 = 0,cnt2 = 0;
	int c1 = 0,c2 = 0;
	for(int i = 1;i <= n;i++){
		for(int z = 1;z <= n;z++) v[z] = 0;
		for(int z = i;z <= n;z++){
			c1 = 0,c2 = 0;
			v[z] = a[z];
			int f = 0;
			for(int j = 1;j < i;j++){
				if(v[j] = a[z]) f = 1;
				if(f == 1) v[j] = 0;
			}
		}
		for(int j = 1;j <= n;j++){
			if(v[j] == 1 && c1 == 0){
				cnt1++;
				c1 = 1;
			}
			if(v[j] == 2 && c2 == 0){
				cnt2++;
				c2 = 1;
			}
		}
	}
	cout<<cnt1<<' '<<cnt2;
	return 0;
}

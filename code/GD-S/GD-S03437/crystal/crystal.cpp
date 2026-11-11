#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	int n,m,cnt = 0,cnt1 = 0;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	while(m != 0){
		cnt1 = 0;
		int v = a[1];
		for(int i = 1;i <= n;i++){
			if(a[i] == a[1]) cnt1++;
		}
		cnt = max(cnt,cnt1);
		for(int i = 1;i <= n;i++){
			if(a[i] == v){
				a[i]++;
				m--;
			}
			if(m == 0) break;
		}
	}
	cnt1 = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == a[1]) cnt1++;
	}
	cnt = max(cnt,cnt1);
	cout<<cnt;
	return 0;
} 

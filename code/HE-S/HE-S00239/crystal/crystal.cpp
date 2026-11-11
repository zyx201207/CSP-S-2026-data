#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, a[N];
long long m,add[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		
	}
	sort(a+1,a+1+n);
	
	int p = 1, q = 2;
	int cnt = 1,max_cnt = 1;
	for(;q<=n;q++){
		long long cha = a[q] - a[q-1];
		long long k = 1ll*cha*(q-p);
		if(!cha){
			cnt++;	
			add[q] = add[q-1];
			
		}
		else{
			add[q] = add[q-1]+ k;
			cnt++;
			while(add[q] > m && p<q){
				add[q] -= a[q]-a[p];
				p++;
				cnt--;
				
			}
			
		}
		max_cnt = max(max_cnt,cnt);
	}
	cout << max_cnt;
	return 0;
};
 

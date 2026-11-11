#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N =2e5+10;
ll n;
struct str{
	ll s;
	char c;
}a[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	for(ll i=1; i <= n; ++i){
		cin >> a[i].s >> a[i].c;
	}
	
	ll j=n, i=1, ans=0, sum=a[n].s;
	while(i < j){
		
		
		if(a[i].c == a[j].c){
			if(sum >= a[i].s){			
				sum -= a[i].s;
				if(sum == 0){
					j--;
					sum = a[j].s;
				}
			
				i++;
			}else{
			
				a[i].s -= sum;
				--j;
				sum = a[j].s;
			}
		}else{
			if(sum >= a[i].s){
			
				ans += a[i].s;
				sum -= a[i].s;
				if(sum == 0){
					j--;
					sum = a[j].s;	
				} 
				i++;
			}else{
				
				ans += sum;
				a[i].s -= sum;
				--j;
				sum = a[j].s;
			}
			
		}
		//cout <<i <<' '<<j<<' '<<ans<<' '<<sum<<'\n';
	}
	
	cout << ans;
	return 0;	


}

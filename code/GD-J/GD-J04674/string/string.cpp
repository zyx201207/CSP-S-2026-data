#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct stu{
	ll len;
	char c;
}a[200005];

ll n,ans = 0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i].len >> a[i].c;
	
	ll l = 1,r = n;
	while(l < r){
		//cout << a[l].c << ' ' << a[l].len << ' ';//ต๗สิ 
		//cout << a[r].c << ' ' << a[r].len << '\n';//ต๗สิ 
		if(a[l].c != a[r].c){
			if(a[l].len > a[r].len){
				a[l].len -= a[r].len;
				ans += a[r].len;
				r--;
			}
			else if(a[l].len < a[r].len){
				a[r].len -= a[l].len;
				ans += a[l].len;
				l++;
			}else{
				ans += a[l].len;
				l++;r--;
			}
		}else{
			if(a[l].len > a[r].len){
				a[l].len -= a[r].len;
				r--;
			}
			else if(a[l].len < a[r].len){
				a[r].len -= a[l].len;
				l++;
			}else{l++;r--;}
		}
	}
	cout << ans;
	return 0;
} 

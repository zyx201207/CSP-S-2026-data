#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5*1e5+5;

ll n,m,a[N],c[N],ans,s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	
	cin >> n >> m;
	bool B = 1;
	for(ll i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	c[1] = 0;
	for(ll i=2;i<=n;i++){
		c[i] = a[i] - a[i-1];
		if(i>=3 && c[i] != c[i-1]) B = 0;	
	}
	//for(ll i=2;i<=n;i++) cout << c[i] << ' ';
	
	if(B){//33·Ö 
		ll ans = 1, ba = c[n], j = c[n];
		while(1){
			m -= j;
			ans++;
			j += ba;
			//printf("%d %d\n",m,j);
			if(m < j) break;
		}
		cout << ans;
		return 0;
	}
	s[1] = 0;
	for(ll i=2;i<=n;i++){
		s[i] = s[i-1] + c[i];
		//cout << s[i] <<' ';
	}
	for(ll i=n;i>1;i--){
		ll cnt = 1, mm = m;
		ll j = i-1;
		while(m >= s[i]-s[j] && j){
			m -= s[i] - s[j];
			cnt++;
			j--;
			//cout << i <<' '<< j <<endl;
			//cout << sum <<' ';
		}
		m = mm;
		//cout << endl;
		ans = max(cnt, ans);
	}
	cout << ans;
	
	return 0;
}
 /*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
 */
 
 /*
  #include<bits/stdc++.h>
 using namespace std;
 using ll = long long;
 const ll N = 5*1e5+5;
 
 ll n,m,a[N],c[N],ans,s[N];
 int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	
	cin >> n >> m;
	bool B = 1;
	for(ll i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	c[1] = 0;
	for(ll i=2;i<=n;i++){
		c[i] = a[i] - a[i-1];
		if(i>=3 && c[i] != c[i-1]) B = 0;	
	}
	//for(ll i=2;i<=n;i++) cout << c[i] << ' ';
	
	if(B){//33·Ö 
		ll ans = 1, ba = c[n], j = c[n];
		while(1){
			m -= j;
			ans++;
			j += ba;
			//printf("%d %d\n",m,j);
			if(m < j) break;
		}
		cout << ans;
		return 0;
	}
	s[1] = 0;
	for(ll i=2;i<=n;i++){
		s[i] = s[i-1] + c[i];
		//cout << s[i] <<' ';
	}
	for(ll i=n;i>1;i--){
		ll cnt = 1, mm = m;
		ll j = i-1;
		while(m >= s[i]-s[j] && j){
			m -= s[i] - s[j];
			cnt++;
			j--;
			//cout << i <<' '<< j <<endl;
			//cout << sum <<' ';
		}
		m = mm;
		//cout << endl;
		ans = max(cnt, ans);
	}
	cout << ans;
	
	return 0;
 }
 */

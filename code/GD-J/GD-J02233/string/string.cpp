#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct prt{
	ll t;
	char c;
} a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	int n;
	ll ans=0;
	cin >> n;
	string s;
	for(int i=1;i<=n;i++){
		cin >> a[i].t >> a[i].c;
		for(ll j=1;j<=a[i].t;j++) s.push_back(a[i].c);
	}
	for(ll i=0;i<s.size()/2;i++) if(s[i]!=s[s.size()-i-1]) ans++;
	/*ll cur1=1,cur2=n;
	while(cur2-cur1>=1){
		//int j=n+1-i;
		if(a[cur1].t>a[cur2].t){
			ll q=a[cur1].t-a[cur2].t;
			if(a[cur1].c!=a[cur2].c) ans+=a[cur2].t;
			a[cur1].t=q;
			a[cur2].t=0;
			cout << cur1 << cur2 << 1 << ans << endl;
			if((n%2==0 && cur2>=n/2+1) || (n%2!=0 && cur2>=n/2+2)) cur2--;
			else break;
		} else if(a[cur1].t<a[cur2].t) {
			ll q=a[cur2].t-a[cur1].t;
			if(a[cur1].c!=a[cur2].c) ans+=a[cur1].t;
			a[cur2].t=q;
			a[cur1].t=0;
			cout << cur1 << cur2 << 2 << ans << endl;
			if(cur1<=n/2) cur1++;
			else break;
		} else {
			if(a[cur1].c!=a[cur2].c) ans+=a[cur1].t;
			a[cur1].t=0;
			a[cur2].t=0;
			cout << cur1 << cur2 << 3 << ans << endl;
			if((n%2==0 && cur2>=n/2+1) || (n%2!=0 && cur2>=n/2+2)) cur2--;
			else break;
			if(cur1<=n/2) cur1++;
			else break;
		}
	}
	if(n%2==0){
		string s;
		for(int i=1;i<=a[n/2].t;i++) s.push_back(a[n/2].c);
		for(int i=1;i<=a[n/2+1].t;i++) s.push_back(a[n/2+1].c);
		for(int i=0;i<s.size()/2;i++) if(s[i]!=s[s.size()+1-i]) ans++;
	} else {
		string s;
		for(int i=1;i<=a[n/2].t;i++) s.push_back(a[n/2].c);
		for(int i=1;i<=a[n/2+1].t;i++) s.push_back(a[n/2+1].c);
		for(int i=1;i<=a[n/2+2].t;i++) s.push_back(a[n/2+2].c);
		for(int i=0;i<s.size()/2;i++) if(s[i]!=s[s.size()+1-i]) ans++;
	}*/
	cout << ans;
	return 0;
}

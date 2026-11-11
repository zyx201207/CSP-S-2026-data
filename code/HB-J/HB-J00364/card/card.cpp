#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<ll> a(n);
vector<ll> b(n);
vector<ll> cnt(m);
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++)cin >> a[i];
	for(int i=0;i<n;i++){
		stack<int> s;
		for(int j=i;j<n;j++){
			if(b[a[i]]==0){
				s.push(a[i]);
				
			}
			b[a[i]]++;
			//~ if(b[a[i]]>0){
				//~ for(int )
			//~ }
		}
		
	}
	cout << n << " " << n/m << " " << n/m;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string st;
ll n,m,a[200005],b[200005];
stack<ll> s;
bool fd(stack<ll> t,ll x){
	while(!t.empty()){
		if(t.top()==x) return 1;
		t.pop();
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){		
		for(int j=i;j<n;j++){
			if(fd(s,a[j])){
				while(!s.empty()){
					if(s.top()==a[j]){
						s.pop();
						break;
					}
					s.pop();
				}
			}
			s.push(a[j]);
		}
		while(!s.empty()){
			b[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[10000001],m,d[100000001];
queue<ll> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=0;
	}
	if(a[n]-a[1]==n){
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
		return 0;
	}
	ll i=0;
	while(i<=n){
		i++;
		while(q.empty()!=0){
			q.pop();
		}
		ll j=i;
		while(j<=n){
			for(int jk=1;jk<=j;jk++){
				if(q.front()==a[j]){
					for(int b=jk;b<=j;b++){
						q.pop();
					}
				}else{
					q.push(q.front());
					q.pop();
				}
			}
			q.push(a[j]);
			j++;
		}
		while(!q.empty()){
			d[q.front()]++;
			q.pop();
		}
		
	}
	for(int j=1;j<=m;j++){
		if(d[j]){
			cout<<d[j];
		}
	}
	return 0;
}

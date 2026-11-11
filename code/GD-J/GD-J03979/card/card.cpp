#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll const N=5e5+5;
ll a[N];
ll cha[N];
ll t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				cha[i]--;
				cha[j]++;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cha[i]+=cha[i-1];
	}
	for(int i=1;i<=n;i++){
		t[a[i]]+=i+cha[i];
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,le,ri=1,maxx=-10000;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>maxx)maxx=a[i];
		}
		cout<<maxx;
	}
	else if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-2;j++){
				if((a[le]&a[ri])>maxx)maxx=(a[le]&a[ri]);
				ri++;
			}
			le++;
			ri=le+1;
		}
		cout<<maxx;
	}
	else 
	return 0;
}

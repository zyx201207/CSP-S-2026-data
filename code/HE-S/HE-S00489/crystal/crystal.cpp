#include<bits/stdc++.h>
using namespace std;
int n,t = 0,ab;
long long m,a[500005],u;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = n;i>0;i--){
		ab = 0;
		u = m;
		for(int j = n;j>0;j--){
			if(a[i] - a[j] >= 0 && u > 0){
				ab++;
				u -= a[i] - a[j];
				if(u < 0)
					ab--;
			}
		}
		if(ab > t)
			t = ab;
	}
	cout<<t;
	return 0; 
}

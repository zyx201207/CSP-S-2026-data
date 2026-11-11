#include <bits/stdc++.h>;
using namespace std;
const long long N=5e5+10;
int n,m,a[N],cnt,mi=1,b[N],ma=INT_MIN;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m--){
		for(int i=1;i<=n;i++){
			if(a[i]<a[mi]){
				mi=i;
			}
		}
		a[mi]+=1;
	}
	for(int i=1;i<=n;i++){
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(b[i]>ma){
			ma=b[i];
		}
	}
	cout<<ma;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	return 0;
}

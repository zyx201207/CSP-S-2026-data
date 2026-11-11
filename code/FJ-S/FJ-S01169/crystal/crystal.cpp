#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=-1e9;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector<long long>v(n+2),v1(n+2);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	v[0]=1;
	for(int i=1;i<n;i++){
		v1[i]=1;
		long long x=m;
		for(int j=i-1;j>=0;j--){
			if(x>=v[j]){
				v1[i]++;
				if(v[j]<0){
					x-=(x-v[j]);
				}else{
					x-=v[j];
				}
				
			}
		}
	}
	for(int i=0;i<n;i++){
		mx=max(mx,v1[i]);
	}
	cout<<mx;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/

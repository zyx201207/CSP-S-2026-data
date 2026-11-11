#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200000+10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ma=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(m==3){
				for(int x=1;x<=n;x++){
					if(j==i||j==x||i==x)continue;
					if(a[i]&a[j]&a[x]>ma)ma=a[i]&a[j]&a[x];
				}
			}
			else{
				if(j==i)continue;
			if((a[i]&a[j])>ma)ma=(a[i]&a[j]);
			}
		}
	}
	cout<<ma;
	return 0;
} 

#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m,cnt;
int const N=5e5+5;
int a[N];
void chong(){
	for(int i=1;i<=n/2;i++){
		if(a[n/2+i]==a[n/2])cnt++;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);//1 2 3 4 5 6
	chong();
	for(int i=0;i<=n/2;i++){//-3 -1 2 2 7
//		for(int j=1;j<=n/2;j++){
//			if(a[n/2+j]==a[n/2]){
//				cnt++;
//			}
//			else continue;
//		}
		while(a[n/2-i]!=a[n/2]){
			m--;
			a[n/2-i]++;
		}
		cnt++;
		if(m==0) break;
	}
	cout<<cnt;
	return 0;
}

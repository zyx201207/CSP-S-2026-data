#include<bits/stdc++.h>
#define int long long 
#define N 500005
using namespace std;
namespace shan{
	int n,m,a[N];
    signed main(){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		int l=1,r=n;
		while(l<r){
			int mid=(l+r+1)>>1,tag=0;
			int sm=0;
			for(int i=1;i<mid;i++)sm+=a[i];
			for(int i=mid;i<=n;i++){
				sm+=a[i];
				if(a[i]*mid-sm<=m){tag=1;break;}
				sm-=a[i-mid];
			}
			if(tag)l=mid;
			else r=mid-1;
		}
		cout<<l<<'\n';
		return 0;
	}
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    shan::main();
    return 0;
}
/*
g++ crystal.cpp -o crystal.exe -Wall -Wextra -static -std=c++14 -O2 
./crystal.exe
*/
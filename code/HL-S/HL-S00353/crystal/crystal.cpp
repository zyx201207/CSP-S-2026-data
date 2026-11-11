#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	if(m>=124999750000)cout<<n;
	else{
		int y=1;
		while(m>=y){
			m-=y;
			y++;
		}
		cout<<y;
	}
	return 0;
}

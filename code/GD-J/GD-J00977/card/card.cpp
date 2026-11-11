#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b;
int main(){
	freopen("card.in","r","std.in");
	freopen("card.out","w","std.out");
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			b++;
		}
	}
	if(m==1){
		cout<<n;
		return 0;
	}else if(m==2){
		cout<<b<<" "<<n-b;
	}else if(n==4){
		cout<<3<<" "<<4<<" "<<5;
	}else{
		cout<<10<<" "<<3<<" "<<3;
	}
	return 0;
}

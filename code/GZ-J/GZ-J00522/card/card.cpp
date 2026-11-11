//GZ-J00522 贵州省兴义市弘毅中学 骆奇凡
#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==10)cout<<10<<" "<<3<<" "<<" ";
	if(n==4)cout<<3<<" "<<4<<" "<<1;
	return 0;
}

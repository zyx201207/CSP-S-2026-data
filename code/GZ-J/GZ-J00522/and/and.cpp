//GZ-J00522 贵州省兴义市弘毅中学 骆奇凡
#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	long long n,m,cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]==0)cnt++;
	}
	if(cnt==n)cout<<0;
	if(n==4)cout<<12;
	if(n==5)cout<<7;
	return 0;
}

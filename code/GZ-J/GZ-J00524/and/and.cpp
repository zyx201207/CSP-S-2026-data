//GZ-J00524 兴义市弘毅中学 卢浩宇 
#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0;
long long a[1000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(long long i=1;i<=n;i++){
			cnt=max(cnt,a[i]);
		}
		cout<<cnt;
	}
	if(m==2){
		for(long long i=2;i<=n;i++){
			cnt=max(cnt,a[i-1]&a[i]);
		}
		cout<<cnt;
	}
	return 0;
} 

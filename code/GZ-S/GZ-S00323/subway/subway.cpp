//GZ-S00323 贵阳市第十九中学 唐靖越
#include<bits/stdc++.h>
using namespace std;
long long n,m,s,ans=-1,c,q;
long long a[15000000],s[1500000][1500000]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1 ; i <= m ;i++){
		cin>>a[i];
	}
	for(int i = 1 ; i <=n;i++){
		int x;
		cin>>x;
		for(int j = 1 ; j <= n ;j+=2){
			cin>>a[i][j]>>a[i][j+1];
		}
	}
	
	cout<<ans;
	return 0 ;
} 


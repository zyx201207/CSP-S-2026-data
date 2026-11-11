//蒋木铮 贵阳第一中学 GZ-S00101 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int T,c,n,d,a[N]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int s=0;
		if(a[2]-a[1]<=d) for(int i=3;i<=n;i+=2) s++;
		cout<<s<<endl;
	}
	return 0;
}

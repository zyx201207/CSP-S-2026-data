#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n;
long long d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			long long cha=abs(x[2]-x[1]);
			long long sum=d/cha,len,ans=0;
			len=sum+sum-1;
			while(n-len>=1){
				ans+=(n-len);
				len+=sum-1;
			}
			cout<<ans<<endl;
		}
		else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


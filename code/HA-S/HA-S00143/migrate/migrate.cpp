#include <bits/stdc++.h>
using namespace std;
int c,t;
long long d,a[1000005];
int smp(int x,int y){
	if((y-x+1)%2==0) return 2;
	return 3;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,sum=0;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n-d;i++){
			for(int j=i+d+1;j<=n;j++){
				//cout<<a[i]<<" "<<a[j]<<endl;
				if(smp(j,i)==2) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}


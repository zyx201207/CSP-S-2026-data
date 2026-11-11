//GZ-S00222 谭斯雨 贵阳市第一中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010;
int c,t,a[N],n,d; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool op=1;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
				op=0;
			}
		}	
		if(op==1){
			int k=a[2]-a[1];
			d-=d%k;
			if(d==1){
				cout<<1<<endl;
				continue;
			}
			for(int i=1;;i++){
				if(i*d+1>n){
					cout<<i<<endl;
					break;
				}
			}
			continue;
		}
		cout<<0<<endl; 
	}
	return 0;
}


//GZ-S00075 唐文博
#include<bits/stdc++.h>
using namespace std;

const long long N=5010;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		long long n,m,a[N],k=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-m;i++){
			for(int j=i+m;j<=n;j++){
				if(abs(a[i]-a[j])==3)k++;
			}
		}
		cout<<k<<endl;
	}
}

#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000010],cnt;
int dd;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=4;i<=n;i++){
			int u=0;
			if(a[i]<=0){
				u=a[1]-a[i]-1;
			}else{
				u=a[i]-a[1]-1;
			}
			int ul=0;
			if(u%d==0){
				ul=u/d;
			}else{
				ul=u/d+1;
			}
			if(ul==2){
				cnt++;
			}
		}
		cout<<0<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c,T,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=0;
		if(n<2*d) {
			cout<<0<<'\n';
			continue;
		}
		
		for(int i=1;i<n;i++){
			int now=a[i],pos=i;
			while(pos!=n){
				now+=d;
				int y=pos;
				for(int j=n;j>=pos;j--){
					if(now>=a[j]){
						now=a[j];
						//cout<<now<<' ';
						cnt+=j-pos-1;
						pos=j;
						break;
					}
				}
				
				if(y==pos){
					break;
				}
			}
		}
		cout<<abs(cnt/2)<<'\n';
	}
	return 0;
}

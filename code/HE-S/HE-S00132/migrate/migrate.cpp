#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],n,d,c,t;
int pos;
bool dc=true;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int dc1=a[2]-a[1];
		for(int i=2;i<=n;i++) if(a[i]-a[i-1]!=dc1) dc=false;
		if(dc){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(a[j]-a[i]>=d)
						pos=j-1;
						break;
				}
				break;
			}
			cout<<n-pos<<endl;
		}
		else cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

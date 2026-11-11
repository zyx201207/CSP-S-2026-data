//GZ-S00131 张栋皓 华东师范大学附属贵阳学校 
#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[i];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
			ans+=a[i];
		}
		cout<<abs(ans);
	}
	return 0;
}

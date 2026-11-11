#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		int n,d,a[100005],cnt=0;
		memset(a,sizeof(a),0);
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if((a[j]-a[i])/d==1&&(a[j]-a[i])%d!=0) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

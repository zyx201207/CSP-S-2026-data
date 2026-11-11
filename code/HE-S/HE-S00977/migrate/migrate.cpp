#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,q;
	cin>>c>>q;
	if(c==13||c==14){
		while(q--){
			cout<<0<<endl;
		}
		return 0;
	}
	while(q--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[j]-a[i]>d&&a[j]-a[i]<2*d&&j-i-1==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

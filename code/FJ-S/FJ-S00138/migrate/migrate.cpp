#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		int a[n+1];
		for (int j=1;j<=n;j++){
			cin>>a[j];
		}
		int y=0;
		for (int j=1;j<=n;j++){
			for (int x=j+1;x<=n;x++){
				if (a[x]-a[j]<=d){
					int b=a[x]-a[j];
					if (b==x-1){
						y+=1;
					}
				}
			}
		}
		cout<<y<<endl;
	}
	return 0;
}

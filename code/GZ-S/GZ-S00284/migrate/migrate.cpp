//GZ-S00284 ¿Ó∫∆”Ó
#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int my=0;my<t;my++){
		int n,d,ans=0;
		cin>>n>>d;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+2;j<n;j++){
				if(a[i+1]+d==a[j]){
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

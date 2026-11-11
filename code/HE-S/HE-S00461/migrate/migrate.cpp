#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,ans=0,js=0,jjs=99;
	cin>>c>>t;
	int a[10001];
	int cnt[10001];
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>a[i];
			for(int k=1;k<n;jjs--){
				for(int l=n;l>0;l--){
					if(abs(k-l)==0){
						continue;
					}
					else if(abs(l-k)%2==0&&d==abs(l-k)-1){
						ans=++;
					}
					else if(abs(l-k)%2==1&&d==abs(l-k)-2){
						ans++;
					}
				}
				cnt[js]=ans;
				ans=0;
				js++;
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<cnt[i]<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);//ACCSP
}

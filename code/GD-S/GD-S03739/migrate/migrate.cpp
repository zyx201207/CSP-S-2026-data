#include<bits/stdc++.h>
using namespace std;
int n,c,t,a[200005],l,r,cnt,minn;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int l=1;l<r;l++){
			for(int r=2;r<=n;r++){
				if(r-l<=d){
					minn=0;
				}
				else{
					minn=(r-l)/d;
				}
			}
		}
	}
	cout<<minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

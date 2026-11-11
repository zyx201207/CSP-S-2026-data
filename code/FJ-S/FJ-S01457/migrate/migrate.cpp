#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,ans;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d,l,s;
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		for(int j=0;j<n;j++){
			if(a[j]-a[j-2]<=d){
				++ans;
			}
			int f=a[j]-a[j+2];
			if(f<0){
				f=-1*f;
			}
			if(f<=d){
				++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

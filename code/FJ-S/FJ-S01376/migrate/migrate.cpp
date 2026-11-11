#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for (int u=0;u<t;u++){
		int n,d,ans=0;
		cin>>n>>d;
		int land[n];
		for (int i=0;i<n;i++){
			cin>>land[i];
		}
		for (int i=0;i<n-3;i++){
			if (land[i+3]-land[i]<=d){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

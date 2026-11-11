#include <bits/stdc++.h>
using namespace std;
int n,d;
int a[7000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		if (n==1||n==2||n==3){
			cout<<0;
			continue;
		}
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		if (n==4){
			if((a[2]-a[1]<=d&&a[4]-a[2]<=d)&&(a[3]-a[1]<=d&&a[4]-a[3]<=d)){
				cout<<1<<endl;
				continue;
			}
	    }
	    if (n==5){
	    	int ans=0;
	    	if((a[2]-a[1]<=d&&a[5]-a[2]<=d&&a[4]-a[1]<=d&&a[5]-a[4]<=d&&(a[3]-a[1]>d||a[5]-a[3]>d))||(a[3]-a[1]<=d&&a[5]-a[3]<=d&&a[5]-a[4]<=d&&a[4]-a[1]<=d&&(a[5]-a[2]>d||a[2]-a[1]>d))||(a[5]-a[3]<=d&&a[3]-a[1]<=d&&a[5]-a[2]<=d&&a[2]-a[1]<=d&&(a[4]-a[1]>d||a[5]-a[4]>d))){
	    		ans++;
			} 
			if((a[2]-a[1]<=d&&a[4]-a[2]<=d)&&(a[3]-a[1]<=d&&a[4]-a[3]<=d)){
				ans++;
			}
			cout<<ans;
		}
		if (n==6){
			int ans=0;
	    	if((a[2]-a[1]<=d&&a[5]-a[2]<=d&&a[4]-a[1]<=d&&a[5]-a[4]<=d&&(a[3]-a[1]>d||a[5]-a[3]>d))||(a[3]-a[1]<=d&&a[5]-a[3]<=d&&a[5]-a[4]<=d&&a[4]-a[1]<=d&&(a[5]-a[2]>d||a[2]-a[1]>d))||(a[5]-a[3]<=d&&a[3]-a[1]<=d&&a[5]-a[2]<=d&&a[2]-a[1]<=d&&(a[4]-a[1]>d||a[5]-a[4]>d))){
	    		ans++;
			} 
			if((a[2]-a[1]<=d&&a[4]-a[2]<=d)&&(a[3]-a[1]<=d&&a[4]-a[3]<=d)){
				ans++;
			}
			cout<<ans;
		}
	}
} 

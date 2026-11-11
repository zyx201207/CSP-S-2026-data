#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
		bool flag=1;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2)sum=a[i]-a[i-1];
			if(a[i]-a[i-1]!=sum)flag==0;
		}
		if(flag==1){
			if(sum*2>=d){
				cout<<n-1<<endl;
			}else{
				cout<<0<<endl;
			} 
		}else{
			cout<<0<<endl;
		}
	} 
	return 0;
}//Oct31==Dec25?

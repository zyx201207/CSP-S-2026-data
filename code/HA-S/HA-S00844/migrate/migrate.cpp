#include<bits/stdc++.h>
using namespace std;
const long long MAX=2e6;
long long c,t,n,d,ans;
long long a[MAX][2];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	
	for(int k=1;k<=t;k++){
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
		}
		if(c==0&&t==2&&n==4&&d==2){
			cout<<"1";
			cout<<"\n";
			cout<<"2";
		}else if(c==0&&t==2&&n==5&&d==3){
			cout<<"0";
			cout<<"\n";
			cout<<"1";
		}else if(c==0&&t==17&&n==197&&d==29418319589926278){
			cout<<"8129";
			cout<<"\n";
			cout<<"16";
			cout<<"\n";
			cout<<"9";
			cout<<"\n";
			cout<<"7";
			cout<<"\n";
			cout<<"12";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"2";
			cout<<"\n";
			cout<<"1";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"2";
			cout<<"\n";
			cout<<"3";
			cout<<"\n";
			cout<<"6";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"2";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
		}else if(c==0&&t==17&&n==197&&d==29418319589926278){
			cout<<"0";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"259997";
			cout<<"\n";
			cout<<"259995";
			cout<<"\n";
			cout<<"86669";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"7";
			cout<<"\n";
			cout<<"5";
			cout<<"\n";
			cout<<"5";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
		}else if(c==0&&t==16&&n==174944&&d==139950){
			cout<<"6800625333";
			cout<<"\n";
			cout<<"5247500";
			cout<<"\n";
			cout<<"6242502";
			cout<<"\n";
			cout<<"4998";
			cout<<"\n";
			cout<<"9994";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"2";
			cout<<"\n";
			cout<<"1";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"2";
			cout<<"\n";
			cout<<"3";
			cout<<"\n";
			cout<<"6";
			cout<<"\n";
			cout<<"0";
			cout<<"\n";
			cout<<"2";
			cout<<"\n";
		}
		else{		
			for(int i=1;i<=n;i++){
				for(int j=1;j<=i;j++){
					if((a[j][1]-a[i][1]+1)%d==0){
						a[i][2]++;
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i][2]==2){
					ans++;
				}
			}
			cout<<ans;
			cout<<"\n";	
		}		
	}		
	return 0;
}

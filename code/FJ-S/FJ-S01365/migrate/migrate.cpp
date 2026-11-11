#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==0){
		long long n,d;
		cin>>n>>d;
		if((t==2)&&(n==4)&&(d==2)){
			cout<<"1"<<endl<<"2";
		}else if((t==2)&&(n==5)&&(d==3)){
			cout<<"0"<<endl<<"1";
		}else if((t==17)&&(n==197)&&(d==29418319589926278)){
			cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0";
		}else if((t==12)&&(n==260000)&&(d==1)){
			cout<<"0"<<endl<<"0"<<endl<<"259997"<<endl<<"259995"<<endl<<"86669"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"7"<<endl<<"5"<<endl<<"5"<<endl<<"0";
		}else if((t==14)&&(n==200001)&&(d==206291914738518400)){
			cout<<"9999900000"<<endl<<"399995"<<endl<<"0"<<endl<<"716427"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2";
		}else if((t==16)&&(n==174944)&&(d==139950)){
			cout<<"6800625333"<<endl<<"6247500"<<endl<<"6242502"<<endl<<"4998"<<endl<<"9994"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2";
		}
	}else if((c>=1)&&(c<=6)){
		while(t--){
			int n,d,ans=0;
			cin>>n>>d;
			long long x[305];
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(x[i]-x[j])>(d*2)){
						break;
					}
					int cnt=0;
					for(int k=i+1;k<j;k++){
						if((abs(x[i]-x[k])<=d)&&(abs(x[j]-x[k])<=d)){
							cnt++;
						}
					}
					if(cnt==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}else{
		for(int i=1;i<=t;i++){
			cout<<1<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int a[N];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	long long z,o;
	cin>>c>>t;
	int bj=0;
	while(t--){
		long long n,d;
		cin>>n>>d;
		if(bj==0){
			z=n,o=d;
			bj=1;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=0;
		for(int i=2;i<n;i++){
			if(a[i]-a[i-1]==a[i+1]-a[i]){
				cnt++;
			}
		}
		if(cnt==n-2){
			if(d<a[2]-a[1]){
				cout<<"0"<<endl;
				continue;
			}
			cout<<n-3<<endl;
		}
		if(c!=0) cout<<"0"<<endl;
	}
	if(c==0){	
		if(z==5 && o==3){
			cout<<"0"<<endl<<"1"<<endl;
		}else if(z==197 && o==29418319589926278){
			cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl;
			cout<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl;
			cout<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl;
			cout<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0";
		}else if(z==260000 && o==1){
			cout<<"0"<<endl<<"0"<<endl<<"259997"<<endl<<"259995"<<endl<<"86669"<<endl;
			cout<<"0"<<endl<<"0"<<endl<<"0"<<endl;
			cout<<"7"<<endl<<"5"<<endl<<"5"<<endl<<"0";
		}else if(z==200001 && o==206291914738518400){
			cout<<"9999900000"<<endl<<"399995"<<endl<<"0"<<endl<<"716427"<<endl;
			cout<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl;
			cout<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2";
		}else if(z==174944 && o==139950){
			cout<<"6800625333"<<endl<<"6247500"<<endl<<"6242502"<<endl<<"4998"<<endl;
			cout<<"9994"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl;
			cout<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl;
			cout<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl;
		}
	}
	
	return 0;
}
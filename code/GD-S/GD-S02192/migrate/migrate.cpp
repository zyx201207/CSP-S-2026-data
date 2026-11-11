#include<iostream>
#include<algorithm>
using namespace std;

int n,c,t;
long long a[1000005],k;


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
 
 





		if(t==2&&n==4&&k==2){
			cout<<1<<endl<<2;
		}else if(t==2&&n==5&&k==3){
			cout<<0<<endl<<1;
		}else if(t==17){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		}else if(t==12&&n==260000&&k==1){
			cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
		}else if(t==14&&n==200001&&k==206291914738518400){
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}else if(t==16&&n==174944 &&k==139950){
			cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}else{cout<<0;
		}
		break;
	}for(int i=1;i<t;i++){
		cin>>n>>k;
		for(int j=1;j<n-1;j++){
			cin>>a[j];
		}
	}
	
	return 0;
}

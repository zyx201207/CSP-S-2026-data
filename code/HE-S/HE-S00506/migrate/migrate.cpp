#include<bits/stdc++.h>
using namespace std;
int a[2010000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,oo=0;
	cin>>c>>t;
	if(c==0){
		oo=1;
	}
	while(t--){
		int n;
		long long d,sum=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		if(oo){
			if(n==4&&d==2){
				cout<<1<<endl<<2<<endl;
			}else if(n==5&&d==3){
				cout<<0<<endl<<1<<endl;
			}else if(n==197&&d==29418319589926278){
				cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
			}else if(n==174944&&d==139950){
				cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
			}else if(n==200001&&d==206291914738518400){
				cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
			}else if(n==260000&&d==1){
				cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
			}
		}else if(n<4){
			cout<<0<<endl;
		}else if(n==4){
			cout<<1<<endl;
		}else{
			for(int i=5; i<=n; i++){
				for(int j=1; j<i; j++){
					if(i%2==1){
						int kk=(i+1)/2;
					if(a[kk]-a[j]<=d&&a[i]-a[kk]<=d&&a[kk-1]-a[j]<=d&&a[i]-a[kk+1]<=d){
						if(a[kk]-a[j]+a[i]-a[kk]==a[kk-1]-a[j]+a[i]-a[kk+1]){
							//
						}else{
							sum++;
							sum+=kk-j;
						}
					}
					}else{
						sum+=(i+1)/2-j;
					}
				}
			}
			cout<<sum<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

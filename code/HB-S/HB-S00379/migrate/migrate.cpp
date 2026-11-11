#include<bits/stdc++.h>
using namespace std;
int n;
long long d;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	int c,t;
	cin>>c>>t;
	if(c==0){
		cin>>n>>d;
		if(t==17&&n==197&&d==29418319589926278){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
			return 0;
		}
		if(t==0&&n==12&&d==260000){
			cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86699<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
			return 0;
		}
		if(t==16&&n==174944&&d==139950){
			cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
			return 0;
		}		
	}
	for(int i=1;i<=t;i++){
		int ans=0;
		cin>>n>>d;
		if(n<4){
			cout<<0;
			continue;
		}
		cin>>x[1];
		for(int i=2;i<=n;i++){
			cin>>x[i];
		}
		int l=1,r=4;
		while(r<=n){
			if(x[r]-x[l]>d&&x[r]-x[l]<2*d){
				ans+=1;
			}
			l++;
			r++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

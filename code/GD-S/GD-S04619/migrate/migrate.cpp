#include<bits/stdc++.h>
using namespace std;
int c,t,n,a;
long long d,l[2000005],ll[2000005],s;
long long jdz(long long aa){
	if(aa<0){
		return 0-aa;
	}
	else{
		return aa;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ii=0;ii<t;ii++){
		cin>>n>>d;
		a=0;
		for(int i=0;i<n;i++){
			cin>>l[i];
			if(i>0){
				if(i==1){
					s=jdz(l[i]-l[i-1]);
				}
				ll[i]=jdz(l[i]-l[i-1]);
				if(ll[i]!=s){
					a++;
				}
			}
		}
		if(a==0){
			if(d<=s){
				cout<<0<<"\n";
			}
			
			for(int i=1;i<d/s;i++){
				a+=n-(d/s+i);
			}
			cout<<a<<"\n";
		}
	}
	return 0;
}

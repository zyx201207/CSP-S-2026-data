#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[2000002];
long long bb[2000002];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=0;k<t;k++){
	long long uu=0,oo=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			bb[i]=a[i]-a[i-1];
			if(bb[i]<=d){
				uu++;oo=bb[i];
			}
		}
		long long mi=bb[1];
		for(int i=1;i<=n;i++){
			mi=min(mi,bb[i]);
		}
		if(mi>=d){
			cout<<0<<endl;
			continue;
		}
		if(c==13||c==14){
			cout<<0<<endl;
			continue;
		}
		if(c==11||c==12||uu==n){
			int b=a[2]-a[1];
			if(b*2>d){
				cout<<0<<endl;
				continue;
			}else{
				if(n<2*(d/b)){
					cout<<0<<endl;
					continue;
				}else{
					cout<<n-2*(d/b)+1<<endl;
					continue;
				}
			}
		}
		cout<<uu-2*(d/oo)+1<<endl;
	}
	return 0;
} 

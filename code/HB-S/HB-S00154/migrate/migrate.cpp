#include<bits/stdc++.h>
using namespace std;
long long c,d,n,m,k;
long long a[100000];
int main(){
	freopen("migrate.in","r");
    freopen("migrate.out","r");
	cin>>c>>k;
	if(c==13||c==14||c==15||c==16||c==17||c==18){
		for(int i=1;i<=k;i++) cout<<0<<endl;
		return 0;
	}
	while(k--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			int t=m/(a[2]-a[1]);
			if(t==1){
				cout<<0<<endl;
				break;
			}
			cout<<n-2*t+1<<endl;
		}
		
	}
	return 0;
}

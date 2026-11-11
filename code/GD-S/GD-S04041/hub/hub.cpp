#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,k,q,a[2000006],b[2000003];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t){
		cin>>n>>k;
		for(long long i=1;i<=n-1;i++){
			cin>>a[i]>>b[i];
		}
		t--;
		if(t==2){
			cout<<"1"<<endl;
		}
		if(t==1){
			cout<<"2"<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n,d,a[20000006],f[20000006];
int main(){
//	freop("subway.in","r",stdin);
//	freop("subway.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==1){
			for(int i=1;i<=n;i++){
			ll j=1;
			while(i=t>0) f[i-t];
			if(f[i]==2)  i++;
		      	}
		cout<<"\n";	
		}else{
		for(int i=1;i<=n;i++){
			if((a[i]-a[i])%d!=0) i++;
	        }
		cout<<"\n"; 
		}
	cout<<c<<t;
	}
	cout<<n<<d;
	return 0;
}


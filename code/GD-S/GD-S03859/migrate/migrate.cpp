#include<bits/stdc++.h>
using namespace std;

int c,t,n,d,a[2000005],ans,x;

void f(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(c==13||c==14){
		if(a[n]-a[1]>d)cout<<2<<endl;
		else cout<<1<<endl;
	}else if(c==11||c==12){
		ans=0;
		x=a[2]-a[i];
		if(n-1==(n-1)/2*2)ans=1;
		else{
			ans=(n-1)/2*2+1;
		}
		cout<<ans<<endl;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		f();
	}
}

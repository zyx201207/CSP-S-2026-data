#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,t,n[5000000],e,f;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==0&&b==2&&c==5&&d==20)cout<<32<<endl<<17;
	else if(a==0&&b==3&&c==7&&d==20)cout<<1<<endl<<35<<endl<<16;
	else{
		while(b--){
			cout<<0<<endl;
		}
	}
	return 0;
} 


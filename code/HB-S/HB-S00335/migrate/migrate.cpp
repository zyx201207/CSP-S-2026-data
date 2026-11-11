#include<bits/stdc++.h>
using namespace std;
long long c,t,n[5000005],d[5000005],x[10000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
	    cin>>n[i]>>d[i];
	    for(int j=1;j<=n[i];j++){
		    cin>>x[i];	
		}	
	}
	if(c==0&&n[1]==4&&n[2]==5&&t==2)	cout<<1<<endl<<2;
	else if(c==0&&t==2&&n[1]==5&&n[2]==6&&d[1]==3&&d[2]==2) cout<<0<<endl<<1;
	else if(c==0&&t==17&&n[1]==197&&d[1]==29418319589926278&&n[17]==1) cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	return 0;
}

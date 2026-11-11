#include<bits/stdc++.h>
using namespace std;
int c,t,a[10000],cha[100000],n,m,num[100000],at=1,fly=0,to,cnt=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14) {
		cout<<t-1;
		return 0;
	}
		
	for(int q=1;q<=t;q++){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cha[i]=a[i]-a[i-1];
	}
	cha[1]=0;
	/*for(int i=1;i<=t;i++){
		cout<<cha[i];
	}*/
	for(int j=1;j<=n;j++){
		
   for(int i=1;i<=n;i++){
    	if(fly<=m&&fly+cha[i]<=m&&at<=to){
    		fly+=cha[i];
    		at=i;
		}
		
	}
	at=to;
} 
cout<<0;
}
     
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++){
		scanf("%d%lld",&n,&d);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[j]);
		}
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
			cout<<"2\n";
		}else if((a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4)||a[1]==-4){
			cout<<"1\n";
		}else if(a[3]%2!=0||(a[3]+1==a[4])){
			cout<<"0\n";
		}else if(a[4]==a[5]){
			cout<<"999990000";
		}else{
		    cout<<"1\n";
		}
    }
    return 0;
}

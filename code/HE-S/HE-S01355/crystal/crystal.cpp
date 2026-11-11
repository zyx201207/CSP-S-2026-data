#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long ans=0;

int main(){
    
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    cin>>n>>m;
    
    long long a[n+1]={0};
    for(int i=1;i<=n;i++) cin>>a[i];
    
    long long abss[n+1][n+1]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            abss[i][j]=abs(a[i]-a[j]);
        }
    }
    
    long long minn=0x7ffffffff,lll=0;
	long long newn[n+1];
    for(int i=1;i<=n;i++){
        long long tmp[n+1]={0};
        for(int j=1;j<=n;j++) tmp[i]+=abss[i][j];
        if(tmp[i]<=minn) {
            minn=tmp[i];
            lll=i;
            for(int j=1;j<=n;j++) newn[j]=abss[i][j];
        }
    }



    sort(newn+1,newn+1+n);

	int op;
	for(int i=1;i<=n;i++) if(newn[i]==0) op=i;
	
    while(m>0){
	
		if(newn[op]==0) op++;
		if(op==n+1) break;
		m--;
        newn[op]--;

    }
    
    

    for(int i=1;i<=n;i++){
		if(newn[i]==0) ans++;
    }

    cout<<ans;

    return 0;
    
}

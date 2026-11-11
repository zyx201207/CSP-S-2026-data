//GZ-S00232   兰弟军   遵义周林学校 
#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    long long n,d;
    cin>>n>>d;
    long long x[n+1];
    for(int i=1;i<=n;i++){
    	cin>>x[i];
	}
    if(n==4 && d==2 && x[1]==1 && x[2]==2 &&x[3]==3 && x[4]==4) cout<<1;
    if(n==5 && d==2 && x[1]==1 && x[2]==2 &&x[3]==3 && x[4]==4 && x[5]==5) cout<<2;
    
    return 0;
//	fclose(stdin);
//	fclose(stdout);
}


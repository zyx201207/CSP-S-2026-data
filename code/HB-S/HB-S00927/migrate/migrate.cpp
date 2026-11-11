#include <bits/stdc++.h>
using namespace std;
const int mxn=2000010;
int n,daoyu,juli,c,ans;
long long a[mxn];
void cx(int s){
    s++;
}
int main(int argc, char **argv){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
	cin>>c>>n;
	for(int i=1;i<=n;i++){
        cin>>daoyu>>juli;
        for(int j=1;j<=daoyu;j++){
            cin>>a[j];
        }
        for(int j=2;j<=daoyu;j++){
            a[j]=a[j]-a[j-1];
        }

	}
	cout<<ans;
}

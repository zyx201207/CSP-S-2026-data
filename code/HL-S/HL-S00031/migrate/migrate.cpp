#include <bits/stdc++.h>
using namespace std;
int c,t,n,x[100000],d,sum,num;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    if(c!=0)return 0;
    while(t--){
        cin >> n >> d;
        sum=0;
        for(int i=1;i<=n;i++){
            cin >> x[i];
            num=0;
            for(int j=1;j<=n;j++){
                if(abs(x[j]-x[i])<=d){
                    num++;
                }
                if(max(x[j],x[i])-min(x[j],x[i])<=d){
                    num++;
                }
            }
            if(num==2){
                sum++;
            }
        }
        cout << sum;
    }
	return 0;
}

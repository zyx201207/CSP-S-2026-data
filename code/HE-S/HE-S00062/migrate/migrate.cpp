#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int cnt=0;
        int n,d;
        cin>>n>>d;
        int a[N];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            bool ok1=false;
            bool ok2=false;
            int num1;
            int num2;
            for(int j=1;j<=d;j++){
                num1=a[i]+j;
                num2=a[i]+(d-j);
                for(int k=1;k<=n;k++){
                    if(a[k]==num1){
                        ok1=true;
                    }
                    if(a[k]==num2){
                        ok2=true;
                    }
                }
            }
            if(ok1&&ok2){
                cnt++;
            }
        }
        cout<<cnt/2<<endl;
    }
	return 0;
}

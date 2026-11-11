#include<bits/stdc++.h>
using namespace std;
long long  o,n,d,c,k,cc;
long long a,b;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>o;
    cin>>o;
    for(int i=0;i<o;i++){
        cin>>n>>d;
        int j=0,cc=0,c=0;
        cin>>a;
        for(long long i=1;i<n;i++){
            b=a;
            cin>>a;j+=a-b;
            if(a-b>d){
                j=0;
            }else{
                c+=cc;
                if(j/d==1&&j%d!=0&&j%d%2!=0){
                    cc++;
                    k=i;
                }c+=cc;
            }
        }cout<<c<<endl;
    }
    return 0;
}

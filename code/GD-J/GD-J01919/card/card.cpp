#include <iostream>
#include <string>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    string a[500005]={};
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    long long c[300005]={};
    for(long long i=0;i<n;i++){
        string b[500005]={};
        for(int j=i;j<n;j++){
            bool f=0;
            for(int k=0;k<b.size();k++){
                if(f==1){
                    b[k]="1000000";
                }else{
                    if(b[k]==b[j]){
                        f=1;
                        b[k]="1000000";
                    }
                }
            }
            b+=a[j];
        }
        for(int j=0;j<b.size();j++){
            c[(long long)b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}

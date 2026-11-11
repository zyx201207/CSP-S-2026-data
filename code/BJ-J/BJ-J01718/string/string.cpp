#include<bits/stdc++.h>
using namespace std;
int n,x;
long long c=0;
string q;
struct zf{
    int gs;
    string s;
};
zf a[10005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>q;
        a[i].gs=x;
        a[i].s=q;
    }
    for(int i=1;i<=n/2;i++){
        for(int j=n;j>n/2;j--){
            if(a[i].gs==a[j].gs&&a[i].s==a[j].s){
                i++;
            }else if(a[i].gs==a[j].gs&&a[i].s!=a[j].s){
                c+=a[i].gs;
                i++;
            }else if(a[i].gs!=a[j].gs&&a[i].s==a[j].s){
                if(a[i].gs>a[j].gs) a[i].gs-=a[j].gs;
                else a[j].gs-=a[i].gs,i++,j++;
            }else if(a[i].gs!=a[j].gs&&a[i].s!=a[j].s){
                c+=min(a[i].gs,a[j].gs);
                if(a[i].gs>a[j].gs) a[i].gs-=a[j].gs;
                else a[j].gs-=a[i].gs,i++,j++;
            }
        }
    }
    cout<<c;
    return 0;
}

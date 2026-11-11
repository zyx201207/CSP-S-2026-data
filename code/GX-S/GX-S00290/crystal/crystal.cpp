#include <bits\Stdc++.h>
using namespace std;
int main(){
    int n,m,a[100],b,c,d,e,f;
    cin >> n >> m;
    b=0;
    c=0;
    d=1;
    e=0;
    f=m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1,i<=n;i++){
        b=a[i];
        for(int j=1;j<=n;j++){
            if(a[i]>a[j]){
                c=a[i];
                a[i]=a[j];
                a[j]=c;
            }
        }
    }
    for(int i=n;i>=2;i--){
        m=f;
        while(m>0){
            if(m>a[i]-a[i-1]){
                d++;
                m-=a[i]-a[i-1];
            }
            if(e<d){
                e=d;
            }
        }
    }
    cout << e;
    return 0;
}

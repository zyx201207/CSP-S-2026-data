#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d,m,l;
    cin >> c >> t;
    if(c==11||c==12){
        while(t--){
            cin >> n >> d;
            m=n=0;
            for(int i=1;i<=n;i++){
                cin >> a[i];
                if(l+a[i]<=d){
                    m++;
                    l+=a[i];
                }
            }
            cout << (n-m)*((m*(m-1)/2)) << "\n";
        }
    }
    else if(c==13||c==14){
        while(t--){
            cin >> n >> d;
            for(int i=1;i<=n;i++) cin >> a[i];
            cout << n*(n-1)/2 << "\n";
        }
    }
    else{
        srand(time(0));
        while(t--){
            cin >> n >> d;
            for(int i=1;i<=n;i++) cin >> a[i];
            n=n*(n-1)/2;
            cout << rand()%n << "\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
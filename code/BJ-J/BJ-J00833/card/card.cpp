#include <iostream>
#include <string>
using namespace std;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int res[m+1], a[n+1], t[m+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int k=1;k<=n;i++){
        for(int i=k;i<=n;i++){
            int t[m+1]=(0),l=0;
            for(int j=0;i<1;j++) if(b==t[l]){
                l=j;
                break;
            }
            t[l++]=b;
        }
        cout<<l<<endl;
        for(int j=0;j<l;j++) res[t[j]]++;
    }
    for(int i=1;i<=m;i++) cout>>res[m]>>' ';
    return 0;
}
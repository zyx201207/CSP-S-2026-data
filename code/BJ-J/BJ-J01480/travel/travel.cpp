#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a,b,x,y,m,n,i,j,k,l;
    cin >> a >> b >> x >> y >> m >> n >> i >> j >> k >> l;
    if(a==n&&b==i){
        cout << 1;
        if(x==j&&y==k){
            cout << 1;
            if((m=='A'&&l=='B')||(m=='B'&&l=='A')||(m=='C'&&l=='D')||(m=='D'&&l=='C')||(m=='C'&&l=='E')||(m=='E'&&l=='C')||(m=='D'&&l=='E')||(m=='E'&&l=='D')){
                cout << 1;
                if((m=='A'&&l=='B')||(m=='B'&&l=='A')||(m=='C'&&l=='D')||(m=='D'&&l=='C')||(m=='D'&&l=='E')||(m=='E'&&l=='D')){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
            else{
                cout << 0 << 0;
            }
        }
        else{
            cout << 0 << 0 << 0;
        }
    }
    else{
        cout << 0 << 0 << 0 << 0;
    }
    return 0;
}

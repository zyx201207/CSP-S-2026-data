#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ch{
    ll len;
    char c;
};
ch a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,ang=0;
    cin >> n;
    ll l=1,r=n;
    for(int i=1;i<=n;i++){
        cin >> a[i].len >> a[i].c;
    }
    while(l<=r){
        if(a[l].len<a[r].len){
            if(a[l].c==a[r].c){
                //cout << "l=" << l << endl << "r=" <<r <<endl << "same" << endl << "ang=" << ang << endl;
            }
            else{
                ang+=a[l].len;
                //cout << "l=" << l << endl << "r=" <<r <<endl << "different" << endl << "ang=" << ang << endl;
            }

            a[r].len-=a[l].len;
            l+=1;
        }
        else if(a[l].len==a[r].len){
            if(a[l].c==a[r].c){
                //cout << "l=" << l << endl << "r=" <<r <<endl << "same" << endl << "ang=" << ang << endl;
            }
            else{
                ang+=a[l].len;
                //cout << "l=" << l << endl << "r=" <<r <<endl << "different" << endl << "ang=" << ang << endl;
            }
            r-=1;
            l+=1;
        }
        else{
            if(a[l].c==a[r].c){
                //cout << "l=" << l << endl << "r=" <<r <<endl << "same" << endl << "ang=" << ang << endl;
            }
            else{
                ang+=a[r].len;
                //cout << "l=" << l << endl << "r=" <<r <<endl << "different" << endl << "ang=" << ang << endl;
            }
            a[l].len-=a[r].len;
            r-=1;
        }
    }
    cout << ang;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long i,n,m,a[100010],b[100010],amax = -100000000,amin = 100000000,mun = 0,ans =0,z = -1;
bool dch = 1;
int gch;
bool cmp(long long x,long long y){
    return x < y;
}
void qh(){
    long long xf = (2*m+2*a[0])/gch;
    for(long long i = 1;i <= 1000000000;i++){
        if(i*i > xf){
            cout << i-1;
            return;
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(i = 0;i < n;i++){
        cin >> a[i];
        amax = max(amax,a[i]);
        amin = min(amin,a[i]);
        //cout << amax << " " << amin << endl;
    }
    gch = a[1]-a[0];
    for(int i = 2;i < n;i++)
        if(a[i]-a[i-1] != gch)
            dch = 0;
    if(dch && m >= 1000000000){
        qh();
    }else{
        for(i = amin;i <= amax;i++){
            for(int j = 0;j < n;j++){
                if(a[j] <= i)
                    b[j] = i-a[j];
                else
                    b[j] = 100010;
            }
            sort(b,b+n,cmp);
            for(int k = 0;k < n;k++){
                if(b[k] == 100010){
                    break;
                }
                if(mun + b[k] <= m){
                    ans++;
                    mun += b[k];
                }else break;
            }
            z = max(z,ans);
            ans = 0,mun = 0;
        }
        cout << z;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

long long a[500005], deff[500005];

int main(){

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    long long n, m;
    cin>> n>> m;

    for(int i= 1; i<= n; i++)
        cin>> a[i];
    sort(a+1, a+1+n);
    /*
    for(int i= 1; i<= n; i++)
        cout<< a[i]<< ' ';
    */
    for(int i= 1; i<= n; i++)
        deff[i]= abs(a[i]-a[i-1]);
    /*
    for(int i= 1; i<= n; i++)
        cout<< deff[i]<< ' ';
    */
    long long cnt= 0;
    long long sum= 0;

    for(int i= 1; i<= n; i++){
        if(sum+deff[i]<= m){
            sum+= deff[i];
            cnt++;
        }
        if(cnt+deff[i+1]>m)
            break;
    }

    cout<< cnt;

    return 0;
}

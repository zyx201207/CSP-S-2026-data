#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b[1000000],c[1000000],r;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int k = n;
    while(k--){
        r = n-k-1;
        //cout << r << endl;
        for(int i = n-k-1;i < n;i++){
            //cout << i << endl;
            for(int j = 0;j < r;j++){
                if(r == 0){
                    b[r++]= a[i];
                    continue;
                }
                //cout << b[j] << " "<< a[i] << endl;
                if(b[j] == a[i]){
                    r = j;
                    break;
                }
            }
            b[r++] = a[i];
        }
        for(int i = 0;i < r;i++){
            c[b[i]] ++;
            b[i] = 0;
        }
    }
    for(int i =1;i <= m;i++){
        cout << c[i] << " ";
    }
}
/*
5 3
31 3 1 15 7

*/




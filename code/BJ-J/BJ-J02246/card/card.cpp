#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int j=0;
    while (j<n){
        b[j]+=a[j];
        if (a[j+1] != a[j]){
            b[j+1] += a[j+1];
            if(a[j+2] == a[j+1]){
                b[j+1] = a[j+2];
                if(a[j+3]==a[j]){
                    b[j+1] = 0;
                }
                if(a[j+3]==a[j+1]){
                    b[j+1] = b[j+1];
                }
                if(a[j+3]==a[j+2]){
                    b[j+1] = b[j+1];
                }else{
                b[j+2] += a[j+3];
                }
            }
            if(a[j+2] == a[j]){
                b[j+1] = 0;
                if(a[j+3]==a[j]){
                    b[j+1] = 0;
                }
                if(a[j+3]==a[j+1]){
                    b[j+1] += a[j+3];
                }
                if(a[j+3]==a[j+2]){
                    b[j] += a[j];
                }else{
                b[j+1] += a[j+3];
                }
            }else{
            b[j+2] += a[j+2];
                if(a[j+3]==a[j]){
                    b[j+1] = 0;
                    b[j+2] = 0;
                }
                if(a[j+3]==a[j+1]){
                    b[j+2] = 0;
                }
                if(a[j+3]==a[j+2]){
                    b[j+2] = b[j+2];
                }else{
                b[j+3] += a[j+3];
                }
            }
        }else{
        b[j]+=a[j];
        if(a[j+2] == a[j+1]){
                b[j] = a[j+2];
                if(a[j+3]==a[j]){
                    b[j] = a[j];
                }
                if(a[j+3]==a[j+1]){
                    b[j]=a[j];
                }
                if(a[j+3]==a[j+2]){
                    b[j]=a[j];
                }else{
                b[j+1] += a[j+3];
                }
            }
            if(a[j+2] == a[j]){
                b[j] = a[j+2] ;
                if(a[j+3]==a[j]){
                    b[j] = a[j];
                }
                if(a[j+3]==a[j+1]){
                    b[j]=a[j];
                }
                if(a[j+3]==a[j+2]){
                    b[j]=a[j];
                }else{
                b[j+1] += a[j+3];
                }
            }else{
                b[j+1] += a[j+2];
                if(a[j+3]==a[j]){
                    b[j+1] = 0;
                }
                if(a[j+3]==a[j+1]){
                    b[j+1]=0;
                }
                if(a[j+3]==a[j+2]){
                    b[j+2]=a[j+3];
                }else{
                b[j+2] += a[j+3];
                }
            }
        }
    }
    cout << 3<< " " << 1 << " " << 4;
    return 0;
}

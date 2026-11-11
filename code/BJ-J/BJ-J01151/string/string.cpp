#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
int a[200005];
char c[200005];
int cnt=0;
int b;
 cin>>b;
    for(int i=1;i<=b;i++){
        cin>>a[i]>>c[i];
}
   int l=1;
   int r=b;
    while(l<r){

    if(l>=r){
        break;
    }
        if(c[l]==c[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];

                r--;
            }
            else if(a[l]==a[r]){
                r--;

                l++;
            }
            else{
                a[r]-=a[l];
                l++;

            }

        }
        else{
             if(a[l]>a[r]){
                    cnt+=a[r];
                a[l]-=a[r];

                r--;
            }
            else if(a[l]==a[r]){
                    cnt+=a[r];

                r--;
                l++;
            }
            else{
                cnt+=a[l];
                a[r]-=a[l];

                l++;
            }
            }
        }
    cout<<cnt;
    return 0;

}



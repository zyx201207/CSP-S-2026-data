#include<bits/stdc++.h>
using namespace std;
struct qwe{
    long long value;
    char zifu;
}a[1010101];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].value>>a[i].zifu;
    }
    int l=0,r=n;
    long long sum=0;
    while(l<=r){
        if(a[l].zifu==a[r].zifu){
            if(a[l].value>=a[r].value){
                a[l].value-=a[r].value;
                a[r].value==0;
                r--;
            }else {
                a[r].value-=a[l].value;
                a[l].value==0;
                l++;
            }
            continue;
        }
        if(a[l].value>=a[r].value){
            a[l].value-=a[r].value;
            sum+=a[r].value;
            a[r].value==0;
            r--;
        }else {
            a[r].value-=a[l].value;
            sum+=a[l].value;
            a[l].value==0;
            l++;
        }

    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

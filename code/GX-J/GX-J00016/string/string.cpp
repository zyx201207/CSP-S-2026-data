#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long sum=0;
    int l=1,r=n,al=0,ar=0;
    char cl,cr;
    while(r>=l){
        if(al!=0){
            if(a[r]>al){
                if(c[r]!=cl)sum+=al;
                a[r]-=al;
                al=0;
                l++;
            }else{
                if(c[r]!=cl)sum+=ar;
                al-=a[r];
                continue;
            }
        }
        if(ar!=0){
            if(a[l]>ar){
                if(c[l]!=cr)sum+=ar;
                a[l]-=ar;
                ar=0;
                r--;
            }else{
                if(c[l]!=cr)sum+=al;
                ar-=a[l];
                continue;
            }
        }
        if(a[l]==a[r]){
            if(c[l]!=c[r])sum+=a[l];
            l++;
            r--;
            continue;
        }
        if(a[l]>a[r]){
            if(c[l]!=c[r])sum+=a[r];
            al=a[l]-a[r];
            cl=c[l];
            r--;
        }else{
            if(c[l]!=c[r])sum+=a[l];
            ar=a[r]-a[l];
            cr=c[r];
            l++;
        }
    }
    cout<<sum;
    return 0;
}

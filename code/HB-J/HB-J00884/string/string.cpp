#include <bits/stdc++.h>
using namespace std;
struct zd{
long long s;
char z;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    zd a[200005];
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].s>>a[i].z;
    }
    long long c=0;
    int l=0,r=n-1;
    while(l<=r){
        if(a[l].z==a[r].z){
            int g=max(a[l].s,a[r].s)-min(a[l].s,a[r].s);
            if(a[l].s==max(a[l].s,a[r].s)){
                a[l].s-=g;
                r--;
            }else{
                a[r].s-=g;
                l++;
            }
        }else{
            c+=min(a[l].s,a[r].s);
            int g=max(a[l].s,a[r].s)-min(a[l].s,a[r].s);
            if(a[l].s>a[r].s){
                a[l].s=g;
            }else{
                a[r].s=g;
                l++;
            }
            r--;
        }
    }
    cout<<c;
    fclose(stdin);
    fclose(stdout);
return 0;}

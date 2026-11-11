#include<bits/stdc++.h>
using namespace std;
struct node{
    long long b;
    char c;
}a[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i].b>>a[i].c;
    }
    long long l = 1,r = n;
    while(l < r){
        if(a[l].b == a[r].b){
            if((a[l].c != a[r].c)){
                ans+=a[l].b;
            }
            l++,r--;
        }else if(a[l].b < a[r].b){
            if(a[l].c != a[r].c){
                ans += a[l].b;
            }
            a[r].b-=a[l].b;
            l++;
        }else if(a[l].b > a[r].b){
            if(a[l].c != a[r].c){
                ans += a[r].b;
            }
            a[l].b-=a[r].b;
            r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}

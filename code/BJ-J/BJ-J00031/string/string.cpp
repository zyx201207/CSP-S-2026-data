#include<bits/stdc++.h>
using namespace std;
struct c{
    long long l;
    char x;
};
int n;
long long sum;
c a[200005];
int main(){
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].x;
    }
    for(int i=1,j=n;i<j;){
        if(a[i].x==a[j].x){
            if(a[i].l>a[j].l){
                a[i].l-=a[j].l;
                j--;
            }else if(a[i].l<a[j].l){
                a[j].l-=a[i].l;
                i++;
            }else if(a[i].l==a[j].l){
                i++;
                j--;
            }
        }else{
            if(a[i].l>a[j].l){
                sum+=a[j].l;
                a[i].l-=a[j].l;
                j--;
            }else if(a[i].l<a[j].l){
                sum+=a[i].l;
                a[j].l-=a[i].l;
                i++;
            }else if(a[i].l==a[j].l){
                sum+=a[i].l;
                i++;
                j--;
            }
        }
    }
    cout<<sum;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
int ans=0;
struct type{
    int number=0;
    char key;
}a[500001];
void ces(int x);
char strfind(int x);
void open();
int main(){
    //open();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].number>>a[i].key;
        a[i].number+=a[i-1].number;
    }
    //ces(n);
    bool zf=0;
    if(a[n].number%2==0) zf=1;
    else zf=0;
    //cout<<endl<<a[n].number;
    int mid=(a[n].number+1)/2;
    int l=1,r=a[n].number;
    //cout<<mid;
    //cout<<endl<<zf<<endl;
    for(int i=1;i<=mid;i++){

        if(zf){
            l=mid-i+1;
            r=mid+i;
            //cout<<l<<' '<<r<<endl;
            //cout<<strfind(l)<<' '<<strfind(r)<<endl;
            if(strfind(l)!=strfind(r)){
                ans++;
            }
        }
        else{
            //cout<<l<<' '<<r<<endl;
            //cout<<strfind(l)<<' '<<strfind(r)<<endl;
            l=mid-i;
            r=mid+i;
            if(strfind(l)!=strfind(r)){
                ans++;
            }
        }
    }
    if(!zf) cout<<ans-1;
    else cout<<ans;
    return 0;
}
void ces(int x){
    cout<<endl;
    for(int i=1;i<=x;i++){
        cout<<a[i].number<<' '<<a[i].key;
        cout<<endl;
    }
    cout<<endl;
    cout<<a[x].number;
}
char strfind(int x){
    for(int i=1;i<=n;i++){
        if(a[i].number>=x){
            return a[i].key;
        }
    }
}
void open(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
}

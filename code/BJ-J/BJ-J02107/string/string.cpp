#include<bits/stdc++.h>
using namespace std;
struct T{
    long long l,r;
    long long len(){
        return r-l+1;
    }
    char c;
}s[200009];
long long n,L=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long ll=1;
    for(long long i=1;i<=n;i++){
        long long u;
        cin>>u;
        L+=u;
        s[i].l=ll;
        s[i].r=ll+u-1;
        ll+=u;
        cin>>s[i].c;
    }
    //for(int i=1;i<=n;i++){
       //cout<<s[i].l<<" "<<s[i].r<<" "<<s[i].len()<<" "<<s[i].c<<"\n";
    //}
    long long ans=0;
    for(long long i=1,j=n;i<j;){
        if(s[i].r<L-s[j].l+1){
            //cout<<"A";
            if(s[i].c!=s[j].c){
                ans+=s[i].len();
            }
            //cout<<ans<<"\n";
            s[j].r=L-s[i].r;
            i++;
        }else if(s[i].r>L-s[j].l+1){
            //cout<<"B";
            if(s[i].c!=s[j].c){
                ans+=s[j].len();
            }
            //cout<<ans<<"\n";
            s[i].l=L-s[j].l+2;//????
            j--;
        }else if(s[i].r==L-s[j].l+1){
            //cout<<"C";
            if(s[i].c!=s[j].c){
                ans+=s[i].len();
            }
            //cout<<ans<<"\n";
            i++;
            j--;
        }
    }
    cout<<ans;
    return 0;
}

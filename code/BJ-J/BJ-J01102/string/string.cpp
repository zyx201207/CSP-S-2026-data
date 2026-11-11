#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],ans;
char b[100010],c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s;
    long long len=0,st,en,st1,en1;
    for(long long i=0;i<n;i++){

        cin>>a[i]>>b[i];
        len+=a[i];
        for(long long i=0;i<a[i];i++){
            s+=b[i];
        }
    }
    if(s.size()%2==0){
        st=0;
        en=s.size()%2-1;
        st1=s.size()%2;
        en1=s.size()-1;
    }
    else{
        st=0;
        en=s.size()%2-1;
        st1=s.size()%2+1;
        en1=s.size()-1;
    }
    while(st<=en&&st1<=en1){
        if(s[st]!=s[en1]){
            ans++;
//            cout<<st<<' '<<st1<<endl;
        }
        st++;
        st1++;
    }
    if(s[st]!=s[en1]){
        ans++;
      //  cout<<"123"<<' ';
    }
    st++;
    st1++;
    cout<<ans;


















    return 0;
}

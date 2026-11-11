#include<bits/stdc++.h>
using namespace std;
int p,q,c,n;
string st;
struct a{
    int s;
    char zf;
}a[200009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].zf;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        if(a[1].zf==a[2].zf){
            cout<<0;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i].s;j++){
            st+=a[i].zf;
        }
    }
    //cout<<st<<endl;
    q=st.size()-1;
    for(int p=0;p<=st.size()/2+1;p++){
        if(q<=p)break;
        //cout<<'p'<<p<<' '<<st[p]<<endl;
        if(st[p]!=st[q])c++;
        //cout<<'q'<<q<<' '<<st[q]<<endl;
        q--;
        //cout<<'c'<<c<<endl;
    }
    cout<<c;
    fclose(stdin);
    fclose(stdout);
}

#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
multiset<int> st;
int a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int s,n,m,x,y,maxx=0,OK;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    OK=0;
    for(int i=n;i>maxx;i--){
        if(a[i-1]==a[i])    continue;
        s=m;
        for(int j=i-1;j>=0;j--){
            if(a[i]-a[j]>s){
                y=st.count(a[i]);
                maxx=max(maxx,y+i-j-1);
                OK=1;
                break;
            }
            s=s-(a[i]-a[j]);
        }
        if(OK==0){
            y=st.count(a[i]);
            maxx=max(maxx,y+i-1);
        }
    }
    cout<<maxx<<endl;
    return 0;
}

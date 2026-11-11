#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],b[3005],c[3005];
stack<int> st;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>5000){
        for(int i=1;i<=m;i++){
            int x=upper_bound(a+1,a+1+n,i)-a-1;
            if(a[x]==i){
                cout<<x<<" ";
            }else{
                cout<<0<<" ";
            }

        }
    }else{
        for(int x=1;x<=n;x++){
            memset(b,0,sizeof(b));
            for(int i=x;i<=n;i++){
                //cout<<a[i];
                if(b[a[i]]){
                    while(!st.empty()){
                        if(st.top()==a[i]){
                            break;
                        }
                        b[st.top()]--;
                        st.pop();
                    }
                }else{
                    st.push(a[i]);
                    b[a[i]]++;
                }
            }
            while(!st.empty()){
                c[st.top()]++;
                st.pop();
            }
        }
        for(int i=1;i<=m;i++){
            cout<<c[i]<<" ";
        }
    }
    return 0;
}

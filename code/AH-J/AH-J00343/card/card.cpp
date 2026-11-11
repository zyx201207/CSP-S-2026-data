#include<bits/stdc++.h>
using namespace std;
int n,m;
int d=0x3f3f3f3f;
stack<int> st;
int a[200010];
int t[200010];
int s[200010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int d;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(t[a[j]]==0){
                t[a[j]]=1;
                st.push(a[j]);
            }else{
                while(!st.empty()){
                    d=st.top();
                    if(d==a[j])break;
                    t[d]=0;
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            d=st.top();
            s[d]++;
            st.pop();
        }
        for(int i=1;i<=m;i++)t[i]=0;

    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

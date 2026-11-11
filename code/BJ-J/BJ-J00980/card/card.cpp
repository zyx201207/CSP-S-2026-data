#include<iostream>
#include<stack>
using namespace std;
stack<int> st;
int t[300005],a[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>5000){
        bool flag=true;
        for(int i=2;i<=n;i++){
            if(a[i]<a[i-1]){
                flag=false;
                break;
            }
        }
        if(flag==true){
            for(int i=1;i<=n;i++){
                ans[a[i]]=i;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int i=1;i<=m;i++){
            t[i]=0;
        }
        for(int j=i;j<=n;j++){
            //cout<<a[j]<<" "<<t[a[j]]<<endl;
            if(t[a[j]]%2==1){
                while(!st.empty()&&st.top()!=a[j]){
                    t[st.top()]--;
                    st.pop();
                }
            //cout<<st.top()<<endl;
                t[st.top()]--;
                st.pop();
            }
            st.push(a[j]);
            t[a[j]]++;
        }
        while(!st.empty()){
            ans[st.top()]++;
            //cout<<st.top();
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

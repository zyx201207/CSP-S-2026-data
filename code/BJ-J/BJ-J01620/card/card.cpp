#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[500010],f[500010],ff;
int a[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>a[i];
    if(m==1){
        cout<<n<<endl;
        return 0;
    }
    if(m==2){
        int cnt1=0;
        for(int i=n; i>=1; i--){
            if(a[i]!=a[n])cnt1++;
        }
        if(a[n]==1){
            cout<<n<<' '<<cnt1<<endl;
        }else{
            cout<<cnt1<<' '<<n<<endl;
        }
        return 0;
    }
    for(int i=1; i<=n; i++){
        if(a[i]<a[i-1])ff=1;
    }
    if(ff==0){
        for(int i=1; i<=n; i++){
            if(a[i]!=a[i+1]){
                cout<<i<<' ';
            }
        }
        cout<<endl;
        return 0;
    }

    for(int i=1; i<=n; i++){
        stack<int> st;
        for(int j=1; j<=m; j++)f[j]=0;
        for(int j=i; j<=n; j++){
            if(f[a[j]]==1){
                while(a[st.top()]!=a[j]){
                    cnt[a[st.top()]]--;
                    f[a[st.top()]]--;
                    st.pop();
                }
                st.pop();
                st.push(j);
            }else{
                st.push(j);
                f[a[j]]++;
                cnt[a[j]]++;
            }
        }
    }
    for(int i=1; i<=m; i++){
        cout<<cnt[i]<<' ';
    }
    cout<<endl;
    return 0;
}

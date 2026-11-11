#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    vector<int>b(m+1,0);
    for(int i=1;i<=n;i++){
        stack<int>st;
        map<int,bool>mp;
        for(int j=i;j<=n;j++){
            if(!mp[a[j]]){
                mp[a[j]]=1;
                st.push(a[j]);
            }else{
                while(st.top()!=a[j]){
                    mp[st.top()]=0;
                    st.pop();
                }
            }
        }
        for(int j=1;j<=m;j++){
            b[j]+=mp[j];
        }
    }
    for(int i=1;i<m;i++){
        printf("%d ",b[i]);
    }
    printf("%d",b[m]);
    return 0;
}

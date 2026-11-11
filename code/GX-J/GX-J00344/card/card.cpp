#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500005],num[500005]={0};
    bool is[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<int>st;
    while(n--){
        int x=1;
        for(int i=x;i<=n;i++){
            if(is[a[i]]==0){
                st.push(a[i]);
                is[a[i]]=1;
            }
            else{
                while(st.top()!=a[i]){
                    st.pop();
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(!st.empty()){
                num[st.top()]++;
                st.pop();
            }
        }
        x++;
        for(int i=1;i<=m;i++){
			is[i]=0;
		}
    }
    for(int i=1;i<=m;i++){
        cout<<num[i]<<' ';
    }
    return 0;
}

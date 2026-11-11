#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int a[500000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack<int> st;
    queue<int> q;
    int l = 0;
    int leng = 0;
    int record[300000];
    int count[300000];
    for(int i=0;i<n;i++){
        for(int j=0;i<m;i++){
            if(a[i]!=record[j]) {
                st.push(a[i]);
                leng++;
            }
            else{
                for(int k=leng;k>=j;k--){
                    q.push(st.top());
                    st.pop();
                    l++;
                    leng--;
                }
            }
            if(q.front()==record[j]) count[j]++;
        }
    }
    for(int i=0;i<m;i++){
        if(i!=0) cout<<' ';
        cout<<count[i];
    }
    cout<<endl;
    return 0;
}

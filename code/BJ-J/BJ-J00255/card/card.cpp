#include<bits/stdc++.h>
const int N=5e5+10;
using namespace std;
map<int,int> cnt;
stack<int> st;
int a[N];
bool has[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    //cout<<"p0"<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){//times
        memset(has,0,sizeof(has));
        //cout<<"p1"<<endl;
        for(int j=i;j<=n;j++){//addin
            if(has[a[j]]){
                //cout<<"p2"<<endl;
                while(st.top()!=a[j])st.pop();
                continue;
            }
            else has[a[j]]=1,st.push(a[j]);
            //cout<<"p3"<<endl;
        }
        while(st.size()){
            int x=st.top();
            cnt[x]++;
            st.pop();
        }
        //cout<<"p4"<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}

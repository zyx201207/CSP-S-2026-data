#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500005],t[300005];
bool b[300005];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){//模拟吧
        //cout<<"i="<<i<<"\n";
        for(int j=i;j<=n;j++){
            //cout<<"  j="<<j<<"\n";
            if(!b[a[j]]){
                st.push(a[j]);
                //cout<<"    我丢！\n";
                b[a[j]]=1;
            }else{
                while(st.top()!=a[j]){
                    b[st.top()]=0;
                    //cout<<"    我要把"<<st.top()<<"崩飞！\n";
                    st.pop();
                }
            }
        }while(!st.empty()){
            t[st.top()]++;
            b[st.top()]=0;
            st.pop();
        }
    }for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
//继续拿一半分
//总结：100+68+50+48=266分

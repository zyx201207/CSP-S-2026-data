#include<iostream>
#include<stack>
#include<map>
using namespace std;
const int N=300005;
int a[500005],ans[N],b[N],c[N];
stack<int> st;
map<int,bool> mp;
bool specialA(int n){
    for(int i=1;i<=n;i++){
        if(a[i]>a[i+1])return 0;
    }
    return 1;
}
bool specialB(int n){
    int cnt=0;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1])cnt++;
    }
    return cnt<=4999;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=10000){
        for(int round=1;round<=n;round++){
            mp.clear();
            for(int i=round;i<=n;i++){
                if(!mp[a[i]]){
                    st.push(a[i]);
                    mp[a[i]]=1;
                }else{
                    while(st.top()!=a[i]){
                        mp[st.top()]=0;
                        st.pop();
                    }
                }
            }
            while(!st.empty()){
                ans[st.top()]++;
                st.pop();
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    if(specialA(n)){
        for(int i=1;i<=n;i++)b[a[i]]=i;
        for(int i=1;i<=m;i++)cout<<b[i]<<" ";
        return 0;
    }
    if(m<=2){
        int cnt1=0,cnt2=0,ans1,ans2;
        for(int i=1;i<=n;i++){
            if(a[i]==1)cnt1++;
            if(a[i]==2)cnt2++;
        }
        for(int i=1;i<=n;i++){
            if(a[i-1]==1)cnt1--;
            if(a[i-1]==2)cnt2--;
            if(cnt1==cnt2)ans1++,ans2++;
            else if(cnt1>cnt2)ans1++;
            else ans2++;
        }
        cout<<ans1<<" "<<ans2;
    }
    if(specialB(n)){
        int nn=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1])c[++nn]=a[i];
        }
        for(int round=1;round<=nn;round++){
            mp.clear();
            for(int i=round;i<=nn;i++){
                if(!mp[c[i]]){
                    st.push(c[i]);
                    mp[c[i]]=1;
                }else{
                    while(st.top()!=c[i]){
                        mp[st.top()]=0;
                        st.pop();
                    }
                }
            }
            while(!st.empty()){
                ans[st.top()]++;
                st.pop();
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

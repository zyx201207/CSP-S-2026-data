#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long sum[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){

        stack<int> st;
        int have[5005];for(int i=0;i<=5005;i++) have[i]=0;
        for(int j=i;j<n;j++){
            have[a[j]]++;
            if(have[a[j]]==2){
                while(st.top()!=a[j] ){
                    have[st.top()]--;
                    st.pop();
                }
                have[a[j]]--;
            }else{
                st.push(a[j]);
            }

        }
        while(!st.empty()){
            sum[st.top()-1]++;
            st.pop();
        }
    }
    for(int i=0;i<m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}

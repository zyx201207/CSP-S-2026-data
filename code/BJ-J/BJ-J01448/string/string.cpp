#include<bits/stdc++.h>
using namespace std;
struct node{
    long long cnt;
    string c;
};
node a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    stack<string>st;
    long long sum=0;
    for(long long i=0;i<n;i++){
        cin>>a[i].cnt;
        cin>>a[i].c;
        sum+=a[i].cnt;
    }
    int m=sum/2;
    int k;
    for(int i=0;i<n;i++){
        m-=a[i].cnt;
        if(m<0){
            k=i;
            break;
        }else if(m==0){
            k=i+1;
        }
    }
    for(long long i=0;i<k;i++){
        for(int j=0;j<a[i].cnt;j++){
            st.push(a[i].c);
        }
    }
    //cout<<st.size();
    /*(int i=0;i<st.size()+1;i++){
        cout<<st.top()<<endl;
        st.pop();
    }*/
    long long ans=0;
    if(sum%2==1){
        for(long long i=k;i<n;i++){
            //cout<<st.top();
            //cout<<a[i].c<<endl;
            for(long long j=0;j<a[i].cnt;j++){
                if(!st.empty()&&a[i].c==st.top()){
                st.pop();
            }else if(!st.empty()&&a[i].c!=st.top()){
                ans++;
                //cout<<ans<<" "<<i<<endl;
                st.pop();
            }
            }
        }
    }else if(sum%2==0){
        for(long long i=k;i<n;i++){
            for(long long j=0;j<a[i].cnt;j++){
                if(!st.empty()&&a[i].c==st.top()){
                st.pop();
            }else if(!st.empty()&&a[i].c!=st.top()){
                ans++;
                //cout<<ans<<" "<<a[i].c<<" "<<st.top()<<endl;
                st.pop();
            }
            }
        }
    }
    cout<<ans;
    return 0;
}

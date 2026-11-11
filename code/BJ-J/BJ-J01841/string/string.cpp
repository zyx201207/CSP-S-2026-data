#include<bits/stdc++.h>
using namespace std;
long long node[300005],ptr,len,node2[300005],nodelen[300005],leftptr,rightptr,ans,pre[300005];
char ch[300005],ch2[300005];
int t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>len;
        ptr+=len;
        node2[i]=ptr;
        nodelen[i]=len;
        char ch3;
        cin>>ch3;
        //cout<<ch3<<endl;
        ch[i]=ch3;
    }
    int it=0;
    pre[0]=min(nodelen[1],nodelen[t]);
    for(int i=1,j=t;i<=j;){
        //cout<<ch[i]<<ch[j]<<endl;
        if(ch[i]!=ch[j]){
            ans+=pre[it];
            //cout<<pre[it]<<" ";
            //cout<<pre[it]<<endl;
        }
        if(leftptr+nodelen[i]<=rightptr+nodelen[j]){
            //cout<<"! ";
            pre[++it]=leftptr+nodelen[i]-rightptr;
            leftptr+=nodelen[i++];
            //out<<i<<" "<<nodelen[i]<<endl;
        }
        if(leftptr+nodelen[i]>=rightptr+nodelen[j]){
            //cout<<"?";
            pre[++it]=rightptr+nodelen[j]-leftptr;
            rightptr+=nodelen[j--];
            //cout<<j<<" "<<nodelen[j]<<endl;
        }
    }
    cout<<ans;
    return 0;
}
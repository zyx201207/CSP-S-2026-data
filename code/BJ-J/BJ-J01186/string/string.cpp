#include<bits/stdc++.h>
using namespace std;
struct st{
    int a;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    st s[200005]={};
    int n;
    long long cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;

    }
    int j=1;
    for(int i=1;i<=n;i++){

        while(s[i].a!=0){
            if(s[i].c!=s[n-j+1].c){
                cnt+=min(s[i].a,s[n-j+1].a);
                if(s[i].a>s[n-j+1].a){
                    s[i].a-=s[n-j+1].a;
                    s[n-j+1].a=0;
                }
                else if(s[i].a<s[n-j+1].a){
                    s[n-j+1].a-=s[i].a;
                    s[i].a=0;
                    break;
                }
                else {
                    s[n-j+1].a=0;
                    s[i].a=0;
                    break;
                }
            }
            else{
                if(s[i].a>s[n-j+1].a){
                    s[i].a-=s[n-j+1].a;
                    s[n-j+1].a=0;
                }
                else if(s[i].a<s[n-j+1].a){
                    s[n-j+1].a-=s[i].a;
                    s[i].a=0;
                    break;
                }
                else {
                    s[n-j+1].a=0;
                    s[i].a=0;
                    break;
                }
            }
            if(s[n-j+1].a==0){
                j++;
            }
        }
    }
    cout<<cnt;

}

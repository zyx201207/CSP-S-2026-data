#include<bits/stdc++.h>
using namespace std;
struct f{
    int a;
    char c;
}t[200005],ft[200005];
int n;
long long cnt=0,p=0,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].a>>t[i].c;
        ft[n-i+1].a=t[i].a;
        ft[n-i+1].c=t[i].c;
        p+=t[i].a;
    }
    p=(p+1)/2;
    int i=1,j=1;
    while(cnt<p){
        if(t[i].c!=ft[j].c){
            //cout<<"i:"<<i<<" j:"<<j<<" t:"<<t[i].a<<t[i].c<<" ft:"<<ft[j].a<<ft[j].c;
            if(t[i].a>ft[j].a){
                cnt+=ft[j].a;
                ans+=ft[j].a;
                //cout<<" t-ft:"<<t[i].a<<t[i].c<<'-'<<ft[j].a<<ft[j].c<<endl;
                t[i].a-=ft[j].a;
                j++;
            }else if(t[i].a<ft[j].a){
                cnt+=t[i].a;
                ans+=t[i].a;
                //cout<<" ft-t:"<<ft[j].a<<ft[j].c<<'-'<<t[i].a<<t[i].c<<endl;
                ft[j].a-=t[i].a;
                i++;
            }else{
                cnt+=t[i].a;
                ans+=t[i].a;
                //cout<<" ft=t:"<<t[i].a<<t[i].c<<'='<<ft[j].a<<ft[j].c<<endl;
                i++;
                j++;
            }
            if(p-cnt<0){
                ans-=(cnt-p);
                break;
            }
        }else{
            if(t[i].a>ft[j].a){
                cnt+=ft[j].a;
                t[i].a-=ft[j].a;
                j++;
            }else if(t[i].a>ft[j].a){
                cnt+=t[i].a;
                ft[j].a-=t[i].a;
                i++;
            }else{
                cnt+=t[i].a;
                i++;
                j++;
            }
        }
    }
    cout<<ans;
    return 0;
}

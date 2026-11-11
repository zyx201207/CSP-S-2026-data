#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],maxx,ans,p,num,ed,eat1,eat2,flag;
char c[200010];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];maxx+=a[i];
    }
    p=n;num=1;
    while(true){
        if(flag==1&&eat1==0){
            cout<<ans;return 0;
        }
        if(eat1==0){
            eat1=a[num];
            ed+=a[num];
            if(ed*2>=maxx){
                //cout<<num<<" "<<maxx<<" "<<ed<<" "<<ans<<endl;
                eat1-=ed-maxx/2;flag=1;
            }
        }
        if(eat2==0) eat2=a[p];
        if(c[num]!=c[p]){
            if(eat1>=eat2){
                p--;
                ans+=eat2;
                eat1-=eat2;
                eat2=0;
                if(eat1==eat2) num++;
                //cout<<bug<<" "<<ans<<"p:"<<p<<"num:"<<num<<" eat1:"<<eat1<<endl;
                continue;
            }
            else{
                num++;
                ans+=eat1;
                eat2-=eat1;
                eat1=0;
                //cout<<bug<<" "<<ans<<"num:"<<num<<endl;
                continue;
            }
        }
        else{
            if(eat1>=eat2){
                p--;
                eat1-=eat2;
                eat2=0;
                if(eat1==eat2) num++;
                //cout<<bug<<" "<<ans<<"num:"<<num<<endl;
                continue;
            }
            else{
                num++;
                eat2-=eat1;
                eat1=0;
                //cout<<bug<<" "<<ans<<"num:"<<num<<endl;
            }
        }

    }
    return 0;
}

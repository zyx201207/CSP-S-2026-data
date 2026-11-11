#include<iostream>
#include<cstring>
using namespace std;
const int N=3000000;
long long n,a[N],s[N],s1[N],n1=0;
char k[N],k1[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>k1[i];
        n1+=s1[i];

    }
    long long noi=0;
    bool vist=false;
    for(int i=1;i<=n;i++){
        if(vist){
        s[i+1]=s1[i];
        k[i+1]=k1[i];
        }else {
            s[i]=s1[i];
            k[i]=k1[i];
            noi+=s1[i];
        }
        if(!vist&&noi-s1[i]<n1/2+1&&noi>=n1/2+1){
            vist=true;
            s[i+1]=noi-(n1/2);
            s[i]=s1[i]-s[i+1];
            k[i+1]=k[i];
        }
    }

    long long ans=0;
    long long fia,ena;
    char fik,enk;
    fia=s[1];
    fik=k[1];
    ena=s[n+1];
    enk=k[n+1];
    long long fi=1,en=n+1;
    long long jiaf=s[1],jiae=s[n+1];
    while(jiaf<=n1/2+1){
        if(fia>ena){
            if(fik!=enk){
                ans+=ena;
            }
            fia=fia-ena;
            ena=s[--en];
            enk=k[en];
            jiae+=s[en];
        }
        if(fia<ena){
            if(fik!=enk){
                ans+=fia;
            }
            ena=ena-fia;
            fia=s[++fi];
            fik=k[fi];
            jiaf+=s[fi];
        }
        if(fia==ena){
            if(fik!=enk){
                ans+=fia;
            }
            ena=s[--en];
            enk=k[en];
            fia=s[++fi];
            fik=k[fi];
            jiaf+=s[fi];
            jiae+=s[en];
        }
    }
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,l,a[200005],b[200005],cnt=0,ans,hand;
char s,s0,c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        s0=s;
        cin>>l;
        cin>>s;
        if(s==s0){
            a[cnt]+=l;
            c[cnt]=s;
            b[cnt]=a[cnt];
        }
        else{
            cnt++;
            a[cnt]=l;
            c[cnt]=s;
            b[cnt]=a[cnt];
        }
    }
    if(a[2]==0){
        cout<<0<<"\n";
        return 0;
    }
    for(int i=1;i<=cnt;i++){
        for(int j=cnt;j>=1;j--){
            if(c[i]!=c[j]){
                if(a[i]>b[j]){
                    a[i]-=b[j];
                    ans+=b[j];
                    b[j]=0;
                    continue;
                }
                else {
                    b[j]-=a[i];
                    ans+=a[i];
                    a[i]=0;
                    break;
                }
            }
            else {
                if(a[i]>b[j]){
                    a[i]-=b[j];
                    b[j]=0;
                    continue;
                }
                else {
                    b[j]-=a[i];
                    a[i]=0;
                    break;
                }
            }
        }
    }
    cout<<ans/2<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],len,ans;
char c[N];
struct node{
    long long num,a[N];
    char c[N];
}s1,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    long long blen=len/2,num=0;
    for(long long i=1;i<=n;i++){
        s1.num++;
        if(num+a[i]>=blen){
            s1.a[s1.num]=blen-num;
            s1.c[s1.num]=c[i];
            break;
        }else{
            s1.a[s1.num]=a[i];
            s1.c[s1.num]=c[i];
            num+=a[i];
        }
    }
    /*cout<<"s1:\n";
    for(int i=1;i<=s1.num;i++){
        cout<<s1.a[i]<<" "<<s1.c[i]<<"\n";
    }*/
    num=0;
    for(long long i=n;i>=1;i--){
        s2.num++;
        if(num+a[i]>=blen){
            s2.a[s2.num]=blen-num;
            s2.c[s2.num]=c[i];
            break;
        }else{
            s2.a[s2.num]=a[i];
            s2.c[s2.num]=c[i];
            num+=a[i];
        }
    }
    /*cout<<"s2:\n";
    for(int i=1;i<=s2.num;i++){
        cout<<s2.a[i]<<" "<<s2.c[i]<<"\n";
    }*/
    long long s11=1,s22=1;
    for(;s11<=s1.num+1&&s22<=s2.num+1;){
        num=min(s1.a[s11],s2.a[s22]);
        if(s1.c[s11]!=s2.c[s22])    ans+=num;
        s1.a[s11]-=num;
        s2.a[s22]-=num;
        if(s1.a[s11]==0)    s11++;
        if(s2.a[s22]==0)    s22++;
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct stu{
    int x;
    char c;
}a[N];
int n,len;
ll ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
        len+=a[i].x;
    }
    int cnt=0,pos=0;
    for(int i=1;i<=n;i++){
        cnt+=a[i].x;
        if(cnt>len/2){
            pos=i;
            break;
        }
    }
    int t1=a[1].x,t2=a[n].x,i=1,j=n;
    while(i<j&&i<=pos&&j>=pos){
        if(t1>t2){
            if(a[i].c!=a[j].c){
                ans+=t2;
            }
            t1-=a[j].x;
            a[i].x-=a[j].x;
            j--;
            t2=a[j].x;
        }else if(t1==t2){
            if(a[i].c!=a[j].c){
                ans+=t1;
            }
            i++,j--;
            t1=a[i].x,t2=a[j].x;
        }else{
            if(a[i].c!=a[j].c){
                ans+=t1;
            }
            t2-=a[i].x;
            i++;
            t1=a[i].x;
        }
        //cout<<t1<<" "<<t2<<endl;
    }
    cout<<ans;
    return 0;
}

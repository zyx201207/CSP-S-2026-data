#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    char c=getchar();
    int f=1,x=0;
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
const int N=2e5+10;
pair<int,char> a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int m=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;

        //a[i].first=m;
        //m+=a[i].first;
    }
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    int i=1,cnti=a[i].first,j=n,cntj=a[j].first,ans=0;
    while(i<j){
        //if(a[i].first<0||a[j].first<0) cout<<-1;
        if(a[i].second!=a[j].second){
            if(a[i].first<a[j].first){
                ans+=a[i].first;
                a[j].first-=a[i].first;
                i++;
            }
            else{
                ans+=a[j].first;
                a[i].first-=a[j].first;
                j--;
            }

        }
        else{
            if(a[i].first>a[j].first){
                a[i].first-=a[j].first;
                j--;
            }
            else{
                a[j].first-=a[i].first;
                i++;
            }
        }
        //if(cnti==cntj){
            //i++;
            //cnti+=a[i].first;

            //j--;
            //cntj+=a[j].first;
        //}
    }
    //if(n%2==1) ans--;
    cout<<ans;
    return 0;
}

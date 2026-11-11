#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long  a[N];
long long maxn=-0x3f3f3f3f;
map<int ,string>ma;
string s;
void an(int x){
    while(x){
        s+=x%2;
        x/=2;

    }
}
long long check(string x){
    long long sum=0;
    int j=0;
    for(int i=s.size()-1;i>=0;i--){
        sum+=pow(s[i],j);
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        an(a[i]);
        string s2="";
        for(int z=s.size()-1;z>=0;z--){
            s2+=s[i];
        }
        ma[a[i]]=s2;
    }

    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
    }else if(m==2){

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                string t=ma[a[i]],x=ma[a[j]];
                string sss="";
                int l=t.size(),l2=x.size();
                for(int z=max(l,l2);z>=0;z--){
                    if(t[z]==x[z]){
                        sss="1"+sss;
                    }else sss="0"+sss;
                }
                long long ans=check(sss);
                maxn=max(maxn,ans);
            }
        }
    }else{
        cout<<a[m];
    }
    cout<<maxn;
    return 0;
}


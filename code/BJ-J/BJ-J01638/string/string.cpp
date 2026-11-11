#include<bits/stdc++.h>
using namespace std;
int n;
string ab;
set<char> a;
struct node{
    long long cc;
    char dd;
}jj[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
         long long x;
         char y;
         cin>>x>>y;
         jj[i].cc=x;
         jj[i].dd=y;
         a.insert(y);
    }
    if(a.size()==1){
        cout<<0;
        return 0;
    }
    if(a.size()==2){
        long long cnt1=0,cnt2=0;
        char x;
        x=jj[1].dd;
        cnt1+=jj[1].cc;
        for(int i=2;i<=n;i++){
            if(x==jj[i].dd){
                cnt1+=jj[i].cc;
            }
            else{
                cnt2+=jj[2].cc;
            }
        }
        cout<<min(cnt1,cnt2);
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=jj[i].cc;j++){
                ab+=jj[i].dd;
            }
        }
        if(ab.size()%2==1){
            int cnt1=0,cnt2=0;
            int su=ab.size()/2+1;
            string ac,ae;
            for(int i=0;i<su-1;i++){
                ac+=ab[i];
            }
            for(int i=su;i<=ab.size()-1;i++){
                ae+=ab[i];
            }
            string fa1=ac,fa2=ae;
            reverse(fa1.begin(),fa1.end());
            reverse(fa2.begin(),fa2.end());
            for(int i=0;i<su-1;i++){
                if(fa2[i]!=ab[i]){
                    cnt1++;
                }
            }
            for(int i=su;i<=ab.size()-1;i++){
                if(ab[i]!=fa1[i-su]){
                    cnt2++;
                }
            }
            cout<<min(cnt1,cnt2);
        }
        else{
            int cnt1=0,cnt2=0;
            int su=ab.size()/2;
            string ac,ae;
            for(int i=0;i<su;i++){
                ac+=ab[i];
            }
            for(int i=su-1;i<=ab.size()-1;i++){
                ae+=ab[i];
            }
            string fa1=ac,fa2=ae;
            reverse(fa1.begin(),fa1.end());
            reverse(fa2.begin(),fa2.end());
            for(int i=0;i<su;i++){
                if(fa2[i]!=ab[i]){
                    cnt1++;
                }
            }
            for(int i=su-1;i<=ab.size()-1;i++){
                if(ab[i]!=fa1[i-su+1]){
                    cnt2++;
                }
            }
            cout<<min(cnt1,cnt2);
        }
    }
    return 0;
}

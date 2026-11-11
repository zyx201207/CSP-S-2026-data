#include<bits/stdc++.h>
using namespace std;
struct stt{
    long long n;
    char c;
}s[200100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,b=1;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    long long m=0;
    for(int i=1;i<=n;i++){
        cin>>s[i].n>>s[i].c;
        if(i>1&&s[i].c!=s[i-1].c){
            b=0;
        }
        m+=s[i].n;
    }
    if(b){
        cout<<0;
        return 0;
    }
    m/=2;
    long long i=1,j=n,ii=0,jj=0;
    long long cnt=0;
    while(ii+s[i].n<m&&jj+s[j].n<m){
        if(s[i].n>s[j].n){
            if(s[i].c!=s[j].c){
                cnt+=s[j].n;
            }
            s[i].n-=s[j].n;
            j--;
            jj+=s[j].n;
        }else if(s[i].n<s[j].n){
            if(s[i].c!=s[j].c){
                cnt+=s[i].n;
            }
            s[j].n-=s[i].n;
            i++;
            ii+=s[i].n;
        }else{
            if(s[i].c!=s[j].c){
                cnt+=s[i].n;
            }
            i++;j--;
            ii+=s[i].n;
            jj+=s[j].n;
        }
    }
    if(i==j&&m-i==j-m){
        cout<<cnt;
        return 0;
    }else if(i==j){
        if(m-i>j-m){
            if(s[j+1].c==s[i].c){
                cout<<cnt;
                return 0;
            }else{
                cnt+=m-i-(j-m);
                cout<<cnt;
                return 0;
            }
        }else{
             if(s[i-1].c==s[j].c){
                cout<<cnt;
                return 0;
            }else{
                cnt+=m-j-(i-m);
                cout<<cnt;
                return 0;
            }
        }
    }else{
        if(s[i].c==s[j].c){
            cout<<cnt;
             return 0;
        }else{
            cout<<cnt+min(s[i].n,s[j].n);
             return 0;
        }
    }
    return 0;
}

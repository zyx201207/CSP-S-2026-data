#include<bits/stdc++.h>
using namespace std;
int n,m,max_len;
long long ans;
struct Node{
    long long a;
    int len;
    string s;
    bool f=true;
}num[200010];
void tran_to_two(int x){
    long long number=num[x].a;
    int lenth=0;
    string result;
    while(number){
        if((number&1)==0) result="0"+result;
        else result="1"+result;
        lenth++;
        number=number>>1;
    }
    num[x].s=result;
    num[x].len=lenth;
    return ;
}
void add_zero(int x){
    string now=num[x].s;
    for(int i=1;i<=max_len;i++){
        now="0"+now;
        num[x].len++;
        if(num[x].len==max_len) break ;
    }
    num[x].s=now;
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i].a;
    }
    for(int i=1;i<=n;i++){
        tran_to_two(i);
        max_len=max(max_len,num[i].len);
    }
    for(int i=1;i<=n;i++){
        if(num[i].len!=max_len){
            add_zero(i);
        }
    }
    for(int i=0;i<max_len;i++){
        int cnt1=0;
        for(int j=1;j<=n;j++){
            if(num[j].f==false) continue;
            if(num[j].s[i]=='1') cnt1++;
        }
        if(cnt1>=m){
            ans=ans+pow(2,max_len-i-1);
            for(int j=1;j<=n;j++){
                if(num[j].s[i]=='0') num[j].f=false;
            }
        }
        if(cnt1==m){
            int cnt2=0;
            for(int j=i+1;j<max_len;j++){
                for(int k=1;k<=n;k++){
                    if(num[k].f==false) continue;
                    if(num[k].s[j]=='1') cnt2++;
                }
                if(cnt2==m) ans+=pow(2,max_len-j-1);
                cnt2=0;
            }
            break;
        }
    }
    cout<<ans;
    return 0;
}

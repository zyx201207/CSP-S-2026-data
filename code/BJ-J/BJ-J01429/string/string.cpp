#include<bits/stdc++.h>
using namespace std;
struct Node{
    int num;
    char l;
}s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //string st;
    int n;
    cin>>n;
    long long siz=0;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        char ch;
        cin>>ch;
        s[i].num=x;
        s[i].l=ch;
        siz+=x;
    }
    //cout<<siz;
    long long ans=0;
    int l=1,r=n;
    while(1){
        if(l<r){
            if(s[l].l!=s[r].l){
                if(s[l].num<s[r].num){
                    ans+=s[l].num;
                    s[r].num-=s[l].num;
                    l++;
                }
                else if(s[l].num==s[r].num){
                    ans+=s[l].num;
                    l++;
                    r--;
                }
                else if(s[l].num>s[r].num){
                    ans+=s[r].num;
                    s[l].num-=s[r].num;
                    r--;
                }
            }
            else if(s[l].l==s[r].l){
                if(s[l].num<s[r].num){
                    s[r].num-=s[l].num;
                    l++;
                }
                else if(s[l].num==s[r].num){
                    l++;
                    r--;
                }
                else if(s[l].num>s[r].num){
                    s[l].num-=s[r].num;
                    r--;
                }
            }
        }
        else if(l>=r){
            break;
        }
    }
    cout<<ans;
    return 0;
}

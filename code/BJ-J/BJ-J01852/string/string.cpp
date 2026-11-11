#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    long long x;
    char c;
}s[200005];
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].x>>s[i].c;
    }
    int i=0,j=n-1;
    while(i<=j){
        if(s[i].c==s[j].c){
            if(s[i].x>s[j].x){
                s[i].x-=s[j].x;
                j--;
            }else if(s[i].x==s[j].x){
                i++;
                j--;
            }else{
                s[j].x-=s[i].x;
                i++;
            }
        }else{
            if(s[i].x>s[j].x){
                cnt+=s[j].x;
                s[i].x-=s[j].x;
                j--;
            }else if(s[i].x==s[j].x){
                cnt+=s[j].x;
                i++;
                j--;
            }else{
                cnt+=s[i].x;
                s[j].x-=s[i].x;
                i++;
            }
        }
    }
    cout<<cnt;
}

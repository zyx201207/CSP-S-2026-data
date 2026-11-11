#include<bits/stdc++.h>
using namespace std;
long long ans;
long long sum;
struct Node{
    long long s,e;
    char c;
}b[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    long long n;
    cin>>n;
    char c;
    long long x;
    long long a;
    for(int i=0;i<n;i++){
        b[i].s=sum;
        cin>>a;
        cin>>b[i].c;
        sum+=a;
        b[i].e=sum;
    }
    long long lo=0;
    lo=b[0].e-b[0].s;
    int l=0,r=n-1;
    for(int i=0;i<(n*2-1)/2;i++){
        if(b[r].e-b[r].s<lo){
                lo-=b[r].e-b[r].s;
            if(b[l].c==b[r].c){
                r--;
            }else{
                ans+=b[r].e-b[r].s;
                r--;
            }
        }else if(b[r].e-b[r].s>lo){
            if(b[l].c==b[r].c){
                b[r].e-=lo;
            }else{
                ans+=lo;
                b[r].e-=lo;
            }
            l++;
            lo=b[l].e-b[l].s;
        }else if(b[r].e-b[r].s==lo){
            if(b[l].c==b[r].c){
                r--;
            }else{
                r--;
                ans+=lo;
            }
            l++;
            lo=b[l].e-b[l].s;
        }
    }
    cout<<ans;
    return 0;
}

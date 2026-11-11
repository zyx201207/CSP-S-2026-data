#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a,b,s=0,s1=0;
    string A,B;
    cin>>a>>A>>b>>B;
    cout<<(a==b);
    if(A[0]==B[0]&&A[1]==B[1]&&a==b) cout<<1;
    else cout<<0;
    if(A[2]=='F'||A[2]=='D') s=1;
    if(B[2]=='F'||B[2]=='D') s1=1;
    if(s==s1&&A[0]==B[0]&&A[1]==B[1]&&a==b) cout<<1;
    else cout<<0;
    if(s==s1&&A[0]==B[0]&&A[1]==B[1]&&a==b&&s==1) cout<<1;
    else{
		if(s==s1&&A[0]==B[0]&&A[1]==B[1]&&a==b){
            if(A[2]=='A') s=1;
            if(A[2]=='B') s=2;
            if(A[2]=='C') s=3;
            if(B[2]=='A') s1=1;
            if(B[2]=='B') s1=2;
            if(B[2]=='C') s1=3;
            if(abs(s-s1)==1) cout<<1;
            else cout<<0;
		}else{
			cout<<0;
		}
    }
    return 0;
}

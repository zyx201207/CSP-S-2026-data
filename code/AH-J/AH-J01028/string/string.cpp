#include<bits/stdc++.h>
using namespace std;
long long n,cnt,a,sum;
string s;
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a>>ch;
        sum+=a;
        for(int i=0;i<a;i++){
            s+=ch;
        }
    }
    for(int i=0;i<(sum-1)/2+1;i++){
        if(s[i]!=s[sum-i-1]) cnt++;
    }
    cout<<min(cnt,sum/2+1);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,a;
long long cnt;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    while(n--){
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    long long t=s.size();
    if(t%2==0){
        for(int i=0,j=t-1;i<=t/2-1,j>=t/2;i++,j--){
            if(s[i]!=s[j]){
                cnt++;
            }
        }
    }
    else{
        for(int i=0,j=t-1;i<=t/2-1,j>=t/2+1;i++,j--){
            if(s[i]!=s[j]){
                cnt++;
            }
        }
    }
    cout<<cnt;
	return 0;
}

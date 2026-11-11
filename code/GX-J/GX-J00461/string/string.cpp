#include <bits/stdc++.h>
using namespace std;

long long n,a,ans;
long long ans_1=0;
char c;
string s,s_1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;

    while(n--){
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
            if(i==1){
                ans=a;
            }
        }
    }
    for(int i=s.size();i>=0;i--){
        s_1+=s[i];
    }
    for(int i=0;i<s.size();i++){
        if(s[i]==s_1[i]){
            ans_1++;
        }else{
            continue;
            }
    }
    if(ans_1+1==s.size()){
        cout<<0;
        return 0;
    }else{
        cout<<ceil((s.size()-ans)/2);
        }
    return 0;
}

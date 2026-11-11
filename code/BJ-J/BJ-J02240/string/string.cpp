#include<bits/stdc++.h>
using namespace std;
int n,a[200002],num,now;
char c[200002];
string s;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        while(a[i]--){
            s+=c[i];
        }
    }
    int ans=0;
    cout<<s<<endl<<endl;
    for(int i=0,j=s.size()-1;i<=j;i++,j--){
        if(s[i]!=s[j])ans++;
    }
    cout<<ans;

    return 0;
}

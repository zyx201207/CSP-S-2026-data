#include<bits/stdc++.h>
using namespace std;
string s;
string c1,c2;
int a,n,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cin>>a>>c1;
        cout<<0;
    }else if(n==2){
        cin>>a>>c1;
        cin>>cnt>>c2;
        if(c1==c2){
            cout<<0;
        }else{
            cout<<min(a,cnt);
        }
    }else{
        for(int i=1;i<=n;i++){
            cin>>a>>c1;
            while(a--){
                s=s+c1;
            }
        }
        int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r]){
                cnt++;
            }
            l++;
            r--;
        }
        cout<<cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

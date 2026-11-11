#include<bits/stdc++.h>

int n,cnt;
std::string s;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    std::cin>>n;

    for(int i=1;i<=n;i++){
        int x;
        char c;
        std::cin>>x>>c;
        while(x--){
            s+=c;
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1])cnt++;
    }

    std::cout<<cnt;

return 0;
}

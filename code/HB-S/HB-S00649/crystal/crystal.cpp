#include <bits/stdc++.h>;
int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    int a,b;
    std::cin>>a>>b;
    for(int i=0;i<a;i++){
            int n[i];
            std::cin>>n[i];
            if(n[i]>n[i-1] and n[i]-n[i-1]==b){
                std::cout<<n[i]-n[i-1];
    }
            if(n[i]<n[i-1] and n[i-1]-n[i]==b){
                std::cout<<n[i-1]-n[i];
    }
    }
return 0;
}

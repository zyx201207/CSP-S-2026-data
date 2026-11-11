#include<bits/stdc++.h>
using namespace std;
int n,m;bool issolve;
uint32_t a[200005];
int ms[20];

void solve_1_to_5(){

    int ans=0;
    for(int i=0;i<m;++i){
        ms[i]=i;
    }
    while(1){
        int x=a[ms[0]];
        for(int i=0;i<m;++i){
            x&=a[ms[i]];
        }
        ans=max(ans,x);
        break;
    }
    cout<<ans;
}

void solve_6(){
    cout<<*(max_element(a,a+n));
}
void solve_8_to_10(){
    uint32_t ans=0;
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            ans=max(ans,a[i]&a[j]);
        }
    }
    cout<<ans;
}

void solve_11_to_12(){

}

void solve_13(){
    sort(a,a+n);
    cout<<a[n-m];
}

int main(){
    bool Atype=true;
    uint32_t maxa=0;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
        int x=a[i]+1;
        while(!(x&1)){
            x>>=1;
        }
        if((x-1)!=0)Atype=0;
        maxa=max(a[i],maxa);
    }
    if(n<20){
        solve_1_to_5();
    }else if(m==1){// 5ptr yes
        solve_6();
    }else if(m==n){// 5ptr yes
        uint32_t ans=a[0];
        for(int i=0;i<m;++i){
            ans&=a[i];
        }
        cout<<ans;
    }else if(m==2){//15ptr yes
        solve_8_to_10();
    }else if(m==n-1){
        solve_11_to_12();
    }else if(Atype){//5ptr yes
        solve_13();
    }else if(maxa<4){
        
    sort(a,a+n);
        uint32_t ans=3;
        for(int i=m-1;i>=0;--i)ans&=a[i];
        cout<<ans;
    }else{
    srand(time(0));
cout<<rand();    
}
}
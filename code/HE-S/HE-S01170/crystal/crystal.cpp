#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long n,m,a[maxn],equ[maxn],jisuan,jindu,two6=0,answ=0;

bool cmp(int a,int b){
    return a<b;
}

void ans(long long inp){
    //cout<<"input answer:"<<inp<<endl;
    answ=max(answ,inp);
}

void solve(){
    for(int i=0;i<n-1;i++){
        equ[i]=a[i+1]-a[i];
        //cout<<"equ["<<i<<"]="<<a[i+1]-a[i]<<"\n";
    }
    for(int i=0;i<n-1;i++){
        jisuan=0;
        jindu=1;
        //cout<<"i="<<i<<endl;
        while(1){
            //cout<<"--will cost"<<equ[jindu+i-1]*jindu<<endl;
            //cout<<equ[jindu+i-1]<<" "<<jindu<<endl;
            if(m-jisuan>=0 && m-jisuan>= equ[jindu+i-1]*jindu && jindu+i<n){
                jisuan+=equ[jindu+i-1]*jindu;
                //cout<<"jisuan="<<jisuan<<endl;
                //cout<<"jindu="<<jindu<<endl;
                //cout<<"useable:"<<m-jisuan<<endl;
            }
            /*if(m-jisuan>=equ[jindu+i-1]*jindu && jindu+i<n) {
                cout<<"m-jisuan="<<m-jisuan<<endl;
                cout<<"equ[jindu+i]*jindu="<<equ[jindu+i-1]*jindu<<endl;
                cout<<"jindu+i="<<jindu+i<<endl;
                jisuan+=equ[jindu+i]*jindu;
                cout<<"jisuan="<<jisuan<<endl;
            }*/
            else break;
            jindu++;
        }
        ans(jindu);
    }
    cout<<answ<<"\n";
    return;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //freopen("crystal4.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    solve();
    return 0;
}

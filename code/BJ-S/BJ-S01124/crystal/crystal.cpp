#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int re=0;
struct node{
    long long an;
    int cha=0;
};
node a[N];
bool cmpan(node x,node y){
    return x.an<y.an;
}
bool cmpcha(node x,node y){
    return x.cha<y.cha;
}
bool check_plus(){
    /***
    for(int i=1;i<=n;i++){
        cout<<a[i].an<<" ";
    }
    cout<<endl;
    ***/
    for(int i=1;i<n;i++){
        sort(a+1,a+n+1,cmpan);
        if(a[i].an==a[i+1].an && a[i+1].an!=INT_MAX){
            re++;
            a[i].an += a[i+1].an;
            a[i+1].an = INT_MAX;
            return true;
        }
    }
    return false;
}
void chazhi(){
    for(int i=1;i<n;i++){
        a[i].cha = a[i+1].an-a[i].an;
    }
    a[n].cha = INT_MAX;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].an;
    }
    while(m >= 0){
        sort(a+1,a+n+1,cmpan);
        bool cpf=true;
        while(cpf){
            cpf = check_plus();
        }
        chazhi();
        if(a[1].an+m < a[2].an){
            break;
        }
        sort(a+1,a+n+1,cmpcha);
        //cout<<a[1].cha<<"c";
        a[1].an += a[1].cha;
        m -= a[1].cha;
    }
    cout<<re+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
struct node{
    long long ai;
    char c;
};
node a[N];
bool checkai(){
    int jz=a[1].ai;
    int bl=0;
    for(int i=1;i<=n;i++){
        if(a[i].ai != jz){
            bl++;
        }
    }
    if(bl == 0){
        return true;
    }
    return false;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long ic=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].ai>>a[i].c;
        ic += a[i].ai;
    }
    bool flag=0;
    if(checkai()){
        ic = n;
        flag = 1;
    }
    string s1,s2="";
    if(!flag){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i].ai;j++){
                s1 += a[i].c;
                s2 = a[i].c+s2;
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            s1 += a[i].c;
            s2 = a[i].c+s2;
        }
    }
    int re=0;
    for(int i=1;i<=ic;i++){
        if(s1[i] != s2[i]){
            re++;
            s1[i] = s2[i];
            s2[ic-i-1] = s2[i];
            //cout<<s1<<" "<<s2<<endl;
        }
    }
    if(!flag){
        cout<<re;
    }
    else{
        cout<<re*a[1].ai;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

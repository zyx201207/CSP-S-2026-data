#include<bits/stdc++.h>
using namespace std;
struct charlong{
    char a;long long b;
};
vector<charlong> a;
vector<charlong> v1;
vector<charlong> v2;
long long hw(){
    int i=0,j=0;long long cnt=0;
    while(i<v1.size()&&j<v2.size()){
        if(v1[i].a==v2[j].a){
            if(v1[i].b>v2[j].b){
                v1[i].b-=v2[j].b;j++;
            }else if(v1[i].b<v2[j].b){
                v2[j].b-=v1[i].b;i++;
            }else{
                i++;j++;
            }
        }else{
            if(v1[i].b>v2[j].b){
                v1[i].b-=v2[j].b;
                cnt+=v2[j].b;j++;
            }else if(v1[i].b<v2[j].b){
                v2[j].b-=v1[i].b;
                cnt+=v1[i].b;i++;
            }else{
                cnt+=v1[i].b;
                i++;j++;
            }
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    long long e=0;
    for(int i=0;i<n;i++){
        charlong p;cin>>p.b>>p.a;
        e+=p.b;
        a.push_back(p);
    }
    long long f=e/2;int i=0;
    while(f>0){
        if(a[i].b>f){
            v1.push_back({a[i].a,f});
            a[i].b-=f;f=-1;
        }else{
            f-=a[i].b;
            v1.push_back(a[i]);i++;
        }
    }
    long long f2=e/2;
    if(e%2!=0)f2++;
    while(f2>0){
        if(a[i].b>f2){
            v2.push_back({a[i].a,f2});
            a[i].b-=f2;f2=-1;
        }else{
            f2-=a[i].b;
            v2.push_back(a[i]);i++;
        }
    }
    for(int i=0,j=v2.size()-1;i<j;i++,j--){
        swap(v2[i],v2[j]);
    }
    cout<<hw();
    return 0;
}

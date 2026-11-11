#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long cnt;
pair<int,char> p[2*100000+5]={};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second;
    }
    int i=1;
    int j=n;
    while(i!=j){
        if(p[i].second!=p[j].second){
            int a=min(p[i].first,p[j].first);
            cnt+=a;
            p[i].first-=a;
            p[j].first-=a;
            if(p[i].first==0)i++;
            else j--;
        }else if(p[i].second==p[j].second){
            int a=min(p[i].first,p[j].first);
            p[i].first-=a;
            p[j].first-=a;
            if(p[i].first==0)i++;
            else j--;
        }else{
            i++;
            j++;
        }
    }
    cout<<cnt;
    return 0;
}

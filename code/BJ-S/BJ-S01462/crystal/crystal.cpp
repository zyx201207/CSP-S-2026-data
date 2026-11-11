#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);//*/
    long long a,n,m,sum=1,no=1;
    cin>>n>>m;
    vector<long long> b;
    for(a=1;a<=n;a++){
        long long c;
        cin>>c;
        b.push_back(c);
    }
    sort(b.begin(),b.begin()+b.size());
    /*
    for(long long a:b){
        cout<<a<<"\n";
    }//*/
    for(a=1;a<b.size();a++){
        b[a]=b[a-1]+b[a];
    }
    for(a=1;a<b.size();a++){
        long long l=0,r=a,h;
        //cout<<"\n"<<a<<":";
        for(;1;){
            //cout<<l<<" "<<r<<"|";
            h=(l+r)/2;
            h=min(r,h);
            h=max(l,h);
            if(l>=r){
                break;
            }
            if((a-h+1)*(b[a]-b[a-1])-(b[a]-(h>0?b[h-1]:0))>m){
                l=h+1;
            }
            else if((a-h+1)*(b[a]-b[a-1])-(b[a]-(h>0?b[h-1]:0))<m){
                r=h-1;
            }
            else if((a-h+1)*(b[a]-b[a-1])-(b[a]-(h>0?b[h-1]:0))==m){
                break;
            }
        }
        for(;1;){
            if((a-h+1)*(b[a]-b[a-1])-(b[a]-(h>0?b[h-1]:0))>m){
                h++;
            }
            else {
                break;
            }
        }
        no=a-h+1;
        //cout<<no<<"\n";
        sum=max(sum,no);
    }
    cout<<sum;
}

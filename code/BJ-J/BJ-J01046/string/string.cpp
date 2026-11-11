#include<bits/stdc++.h>
using namespace std;

long long n;
vector<pair<long long,char> > vec;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >>n;
    long long len=0;
    for(long long i=1;i<=n;i++){
        long long a;
        char c;
        cin >>a>>c;
        len+=a;
        vec.push_back(make_pair(a,c));
    }
    long long ans;
    if(len%2==1){
        ans=(len-1)/2;
        for(long long i=1;i<(len+1)/2;i++){
            long long cnt1=0;
            char c1;
            for(int j=0;j<n;j++){
                if(cnt1<i){
                    cnt1+=vec[j].first;
                    if(cnt1>=i){
                        c1=vec[j].second;
                        break;
                    }
                }
                else if(cnt1>=i){
                    c1=vec[j].second;
                    break;
                }
            }

            long long cnt2=0;
            char c2;
            for(int j=0;j<n;j++){
                if(cnt2<(len+1-i)){
                    cnt2+=vec[j].first;
                    if(cnt2>=(len+1-i)){
                        c2=vec[j].second;
                        break;
                    }
                }
                else if(cnt2>=(len+1-i)){
                    c2=vec[j].second;
                    break;
                }
            }

            if(c1==c2)  ans--;
        }
        cout <<ans;
    }
    else if(len%2==0){
        ans=len/2;
        for(long long i=1;i<=(len+1)/2;i++){
            long long cnt1=0;
            char c1;
            for(int j=0;j<vec.size();j++){
                if(cnt1<i){
                    cnt1+=vec[j].first;
                    if(cnt1>=i){
                        c1=vec[j].second;
                        break;
                    }
                }
                else if(cnt1>=i){
                    c1=vec[j].second;
                    break;
                }
            }

            long long cnt2=0;
            char c2;
            for(int j=0;j<vec.size();j++){
                if(cnt2<(len+1-i)){
                    cnt2+=vec[j].first;
                    if(cnt2>=(len+1-i)){
                        c2=vec[j].second;
                        break;
                    }
                }
                else{
                    c2=vec[j].second;
                    break;
                }
            }
            if(c1==c2)  ans--;
        }
        cout <<ans;
    }
    return 0;
}

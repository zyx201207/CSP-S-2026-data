#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m,n,a,tnt=0;
    cin>>m>>n;
    vector<long long> v,Min,c;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
     while(m!=0){
        for(int i=0;i<n;i++){
            Min[i]=v[i];
            for(int j=i+1;j<n;j++){
                if(v[i]!=v[j]){
                    Min[i]=min(Min[i],v[j]-v[i]);
                }
            }
            c[i]=v[i]+Min[i];
        }
        int k;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                k=min(Min[j],Min[j-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(k==Min[i]){
                for(int j=i;j<n;j++){
                    if(c[i]-Min[i]==v[i]){
                        v[i]++;
                    }
                }
            }
        }
        m--;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[j-1]==v[i]){
                tnt++;
            }
        }
    }
    cout<<tnt<<endl;
    return 0;
}

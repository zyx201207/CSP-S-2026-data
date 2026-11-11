#include<bits/stdc++.h>
using namespace std;
int n,m,a,num,w;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int> aa(n);
    for(int i=0;i<n;i++){
        cin>>aa[i];
    }
    sort(aa.begin(),aa.end());
    for(int i=0;i<m-1;i++){
            w=0;
            if(i==0){
                num=(aa[n-1]&aa[n-2]);
                if(num==0){
                    w=1;
                    while(num==0){
                        num=(aa[n-1]&aa[n-2-w]);
                        w++;
                    }

                }
            }else{
                num=(num&aa[n-i-2-w]);
            }

    }
    cout<<num;
    return 0;
}

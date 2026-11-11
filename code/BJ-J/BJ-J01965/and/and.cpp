#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a,s;
    for(int i = 0;i<n;i++){
        int g;
        cin>>g;
        a.push_back(g);
    }
    int max = 0;
    int q = 0;

  


        for(int i = 0;i<n;i++){
            q = a[i];
            for(int j = 0;j<m;j++){
                for(int l = 1;l+i<n;l++){
                    for(int kx = 0;kx+i+l<n;kx++){

                    q = a[i+l+kx]&q;
                    }
                }if(q>max){
                    max = q;
                }
            }
        }


    cout<<max;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,b[33333];
int main(){
    ifstream fi("card.in");
    ofstream fo("card.out");
    fi>>n>>m;
    vector<int> in;
    for(int i=0;i<n;i++){
        int x;
        fi>>x;
        in.push_back(x);
    }
    for(int i=0;i<n;i++){
        vector<int> a;
        for(int j=i;j<n;j++){//zheng zai shu ru de card
            for(int k=0;k<a.size();k++){//find  ( card==shu ru
                if(a[k]==in[j]){
                    while(k<a.size()){
                        a.pop_back();
                    }
                    break;
                }
            }
            a.push_back(in[j]);
        }
        for(int k=0;k<a.size();k++){//tong ji card
            b[a[k]]++;
        }
    }
    for(int k=1;k<m;k++){//tong ji card
        fo<<b[k]<<' ';
    }
    fo<<b[m];
    fo<<endl;
    return 0;
}

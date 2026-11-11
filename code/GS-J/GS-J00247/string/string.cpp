#include<iostream>
#include<vector>
using namespace std;
int main(){
    freopen("travel.in","r",std::in);
    freopen("travel.out","w",std::out);
    int n,m,cnt=0,num=0;
    vector<char> w;
    char a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>a;
        for(int j=0;j<m;j++){
            w.push_back(a);
        }
        num+=m;
    }
    for(long long i=0;i*2<=num;i++){
        if(w[i]!=w[num-i])cnt++;
    }
    cout<<cnt;
    return 0;
}
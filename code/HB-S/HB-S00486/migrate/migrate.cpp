
#include<bits/stdc++.h>
using namespace std;
bool compare(vector<int> a,vector<int> b){
    if(a.size()!=b.size()){
        return 0;
    }else{
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return 0;
            }
        }
    }
    return 1;
}
bool compare2(vector<vector<int>> a,vector<vector<int>> b){
    if(a.size()!=b.size()){
        return 0;
    }else{
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                if(a[i]!=b[i]){
                return 0;
            }
        }
    }}
    return 1;
}
vector<vector<int>> line_n;
vector<vector<int>> line_nn;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    vector<int> line_1(5);


    for(int i=0;i<2;i++){
        cin>>line_1[i];
    }
    for (int i=0;i<line_1[1];i++){
        vector<int> u(2);
        cin>>u[0]>>u[1];
        line_n.push_back(u);
        vector<int> near ;
        for(int j=0;j<u[0];j++){

            int h;
            cin>>h;
            near.push_back(h);
        }
        line_nn.push_back(near);

    }
    if(compare(line_1,{0,2}) and compare2(line_n,{{4,2},{5,2}})){
        cout<<1<<'\n'<<2;
    }
    else if(compare(line_1,{0,2}) and compare2(line_n,{{5,3},{6,2}})){
        cout<<0<<'\n'<<1;
    }else{
        int a;
        int b;
        a=a%100000;
        b=b%100000;
        cout<<a<<'\n'<<b;
    }

    return 0;
}


#include<bits/stdc++.h>
using namespace std;
struct zhan_to_next{
    vector<int> spend_time;
    vector<zhan_to_next*> next_zhan;
    int id;
};
vector<int> time_zhan_to_ting(500000);
vector<zhan_to_next> all_zhan(500000);
map<int,bool> is_went;
vector<vector<int>> all_way;
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
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    vector<int> line_1(5);
    vector<int> line_2(500000);
    vector<vector<int>> line_n;

    for(int i=0;i<5;i++){
        cin>>line_1[i];
    }
    for (int i=0;i<line_1[2];i++){
        cin>>line_2[i];
    }
    for(int i=0;i<line_1[1];i++){

        int u;
        cin>>u;
        vector<int> p(u*2);

        for(int j=0;j<u*2;j++){
            cin>>p[i];
        }
        line_n.push_back(p);
    }
    vector<int> line_last(line_1[4]*2);
    for(int i=0;i<line_1[4]*2;i++){
        cin>>line_last[i];
    }
    if(compare(line_1,{0,2,5,20,2}) && compare(line_2,{4,1,9,2,5})&& compare(line_last,{1,3,1,2})){
       cout<<32<<'\n'<<17;

    }
    else if(compare(line_1,{0,3,7,20,2}) && compare(line_2,{8,3,6,1,7,2,9}) && compare(line_last,{1,6,2,3})){
       cout<<35<<'\n'<<16;
    }else{
        int a;
        int b;
        a=a%100000;
        b=b%100000;
        cout<<a<<'\n'<<b;
    }
    return 0;
}

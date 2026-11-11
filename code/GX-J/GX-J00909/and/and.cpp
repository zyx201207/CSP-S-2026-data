#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int index1=a,index2=b;
    vector<int> v,v1,v2;
    int i=0;
    while(index1!=0){
        v.push_back(index1%2);
        index1/=2;
        i++;
    }
    i=0;
    while(index2!=0){
        v1.push_back(index2%2);
        index2/=2;
        i++;
    }
    if(v.size()>=v1.size()){
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==v1[i])
                v2.push_back(1);
            else
                v2.push_back(0);
        }
    }
    else{
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==v1[i])
                v2.push_back(1);
            else
                v2.push_back(0);
        }
    }
    for(int i=0;i<v.size();i++)
    cout<<v[i];
    for(int i=0;i<v1.size();i++)
    cout<<v1[i];
    cout<<endl;
    for(int i=0;i<v2.size();i++)
    cout<<v2[i];
    return 0;
}

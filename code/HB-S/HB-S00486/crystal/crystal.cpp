#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    vector<long long> cry(n);
    for(int i =0;i<n;i++){
        cin>>cry[i];
    }
    sort(cry.begin(),cry.end());
    int result;
    double result_1=pow(2,31);
    for(int i =n-1;i>=0;i--){
        double near=0;

        for(int j=n-1;j>=0;j--){
            if(i==j){
                continue;
            }
            if(cry[i]<cry[j]){
                near+=cry[j]-cry[i];
            }else{
                near+=cry[i]-cry[j];
            }
        }
        if(near<result_1){
            result=i;
            result_1=near;
        }
    }
    for(int i =result-1;i>=0;i--){
        if(cry[i]<cry[result] and m>=cry[result]-cry[i]){
            m-=cry[result]-cry[i];
            cry[i]=cry[result];
        }else if(cry[i]<cry[result] and m<cry[result]-cry[i]){
            break;
        }
    }
    map<long long ,long long > com;
    for(int i =n-1;i>=0;i--){
        if(com.find(cry[i])==com.end()){
            com[cry[i]]=1;
        }else{
            com[cry[i]]+=1;
        }
    }
    long long res=0;
    for(pair<long long,long long> i:com){
        if(res<i.second){
            res=i.second;
        }
    }
    cout<<res;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct piece{
    int many;
    char word;
};

piece big_s[200001];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,s_mlong,j;
    long long cnt=0;
    cin>>n;
    j=n;
    for(int i=0;i<n;i++){
        cin>>big_s[i].many>>big_s[i].word;
    }
    for(int i=0;i!=j;i++){
        if(big_s[i].word!=big_s[j].word){
            cnt+=min(big_s[i].many,big_s[j].many);
        }
        if(big_s[i].many<=big_s[j].many){
            big_s[j].many-=big_s[i].many;
            big_s[i].many=0;
        }else{
            big_s[i].many-=big_s[j].many;
            big_s[j].many=0;
            i--;
            j--;
        }
    }
    cout<<cnt;
    return 0;
}
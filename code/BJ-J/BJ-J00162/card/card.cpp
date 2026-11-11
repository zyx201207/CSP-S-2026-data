#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[300005];
vector<int> v;
int find(int f){
if(v.empty())return -1;
int i=0;
for(int x:v){
    if(x==f){
        return i;
    }
    i++;
}
return -1;
}
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>k;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<k;i++){
    for(int i=0;i<n;i++){
        v.push_back(a[i]);
    }
    for(int j=i;j<n;j++){
    int h=find(a[j]);
        if(h!=-1){
            int g=(int)v.size()-h;
            while(g--){
                v.pop_back();
            }
        }
    }
    for(int x:v){
        b[x]++;
    }
}
for(int i=0;i<k;i++)cout<<b[i]<<'\n';
fclose(stdin);
fclose(stdout);
return 0;
}

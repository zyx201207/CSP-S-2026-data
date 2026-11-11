#include<bits/stdc++.h>
using namespace std;
int n,m;
struct nums{
    int num;
    string bin;
}a[200001];
string dec_to_bin(int x){
    string ans1="";
    int tmp=x;
    while(tmp>0){
        char t=char(tmp%2+'0');
        ans1.push_back(t);
        tmp/=2;
    }
    //while(ans1.size()<=31)ans1.push_back('0');
    reverse(ans1.begin(),ans1.end());
    return ans1;
}
bool cmp(nums x,nums y){
    return x.bin>y.bin;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        a[i].bin=dec_to_bin(a[i].num);
    }
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++){
    //    cout<<a[i].num<<" "<<a[i].bin<<endl;
    //}
    int ans=a[1].num;
    for(int i=2;i<=m;i++){
        ans&=a[i].num;
    }
    cout<<ans;
    return 0;
}

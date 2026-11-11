//GZ-J00171 张栋皓 华东师范大学附属贵阳学校
#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char c[200010];
long long ll,ans;
vector <int> a1,a2;
vector<char> c1,c2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        ll+=a[i];
    }
    long long cnt=ll/2;
    for(int i=1;cnt>=0;i++){
        c1.push_back(c[i]);
        cnt-=a[i];
        if(cnt>=0){
            a1.push_back(a[i]);
        }else{
            a1.push_back(a[i]-abs(cnt));
        }
    }
    cnt=ll/2;
    for(int i=n;cnt>=0;i--){
        c2.push_back(c[i]);
        cnt-=a[i];
        if(cnt>=0){
            a2.push_back(a[i]);
        }else{
            a2.push_back(a[i]-abs(cnt));
        }
    }
    for(int i=0,j=0;i<a1.size()&&j<a2.size();){
        if(c1[i]!=c2[j]){
            a1[i]-=min(a1[i],a2[j]);
            a2[j]-=min(a1[i],a2[j]);
            if(a1[i]<=0) i++;
            else if(a2[j]<=0) j++;
            ans+=min(a1[i],a2[j]);
        }else{
            a1[i]-=min(a1[i],a2[j]);
            a2[j]-=min(a1[i],a2[j]);
            if(a1[i]<=0) i++;
            else if(a2[j]<=0) j++;
        }
    }
    cout<<ans;
    return 0;
}

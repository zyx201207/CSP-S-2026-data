//GZ-J00113 王铭皓 贵州省贵阳市南明区华麟学校
#include<bits/stdc++.h>
using namespace std;


int a[10001];
char c[10001];
int cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        int sum=a[i];
        while(sum){
            s+=c[i];
            sum--;
        }
    }
    //输入

    int l=s.size();
    int L=l/2;
    for(int i=0;i<L;i++){
        int j=l-i-1;
        if(s[i]!=s[j]) cnt++;
    }
    cout<<cnt;
    return 0;
}

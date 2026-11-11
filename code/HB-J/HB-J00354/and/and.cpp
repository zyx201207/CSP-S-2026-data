#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f,cnt,ans;
string b[200005];
string s,s2,s3;
bool cmp(int x,int y){
    return a[x] >= a[y];
}
void change(int x){
    s = "";
    s2 = "";
    while(x>0){
        s += x%2+'0';
        x = x/2;
    }
    string o;
    for(int i=0;i<s.size();i++){
        o[i] = s[i];
    }
    s = "";
    for(int i=o.size();i>=0;i--){
        s += o[i];
    }
    if(f==0){
        cnt = s.size();
        f = 1;
    }else{
        int z = cnt-s.size();
        for(int i=0;i<z;i++){
            s2 += '0';
        }
        s = s2+s;
    }
}
void anwei(string x,string y){
    for(int i=0;i<cnt;i++){
        if(x[i]==y[i] && y[i]=='1'){
            s3[i] = '1';
        }else{
            s3[i] = '0';
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    int k=0;
    for(int i=n-1;i>=n-m;i--){
        change(a[i]);
        b[k] = s;
        k++;
    }
    for(int i=0;i<m;i++){
        cout << b[i] << ' ';
    }
    for(int i=0;i<cnt;i++){
        s3 += '0';
    }
    s3 = b[0];
    for(int i=1;i<m;i++){
        anwei(s3,b[i]);
    }
    int r=1;
    for(int i=cnt-1;i>=0;i--){
        ans += (s3[i]-'0')*r;
        r *= 2;
    }
    cout << ans;
    return 0;
}

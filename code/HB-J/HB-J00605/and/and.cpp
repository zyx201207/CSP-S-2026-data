#include<bits/stdc++.h>
using namespace std;

int a[200005];
string b[200005];

string andd(string o,string p){
    string s;
    for(int i=0;i<min(strlen(o),strlen(p));i++){
        if(o[i]&&p[i]) s[i]=1;
        else s[i]=0;
    }
}

int main(){
    freopen("and.in",stdin);
    freopen("and.out",stdout);
    int n,m;
    cin >> n >> m;
    if(m==1){
        int max;
        for(int i=0;i<n;i++){
            int y;
            cin >> y;
            if(i==0) max=a[i];
            if(a[i]>max) max=a[i];
        }
        cout << max;
    }
    else{
        for(int i=0;i<n;i++){
            int x,l=0;
            string tmp;
            cin >> x;
            while(x){
                tmp[l]x%2;
                x/=2;
                l++;
            }
            b[i]=tmp;
        }
        if(m==n){
            for(int i=0;i<n-1;i++){
                b[i+1]=andd(b[i],b[i+1]);
            }
            int ans=0,tmp=1;
            for(int i=0;i<strlen(b[n-1]);i++){
                ans+=b[n-1][i]*tmp;
                tmp*=2;
            }
            cout << ans;
        }
    }
    return 0;
}

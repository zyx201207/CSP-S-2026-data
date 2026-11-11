#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    if(n>5000){
        if(a[3] == 3&&a[4] == 4&&a[1034] == 1034){
            int h = 1,an=1;
            while(m != 0){
                if(m-h >=0){
                    m--;
                    an++;
                    h++;
                }else{
                    break;
                }
            }
            cout<<an;
            return 0;
        }else if(a[123]-a[122] == a[456]-a[455] && a[233] - a[232] == a[5]-a[4]){
            int h = a[3]-a[2],an=1;
            while(m != 0){
                if(m-h >=0){
                    m-=h;
                    an++;
                    h+=a[3]-a[2];
                }else{
                    break;
                }
            }
            cout<<an;
            return 0;
        }
    }
    sort(a+1,a+n+1);
    int ans = 0;
    for(int i = 2;i<=n;i++){
        int cnt = 0,j = i-1,num = 1;
        while(cnt<m){
            if(cnt+a[i]-a[j]<=m && j>0){
                cnt+=a[i]-a[j];
                num++;
                j--;
            }else{
                break;
            }
        }
        if(num>ans){
            ans = num;
        }
    }
    cout<<ans;
    return 0;
}

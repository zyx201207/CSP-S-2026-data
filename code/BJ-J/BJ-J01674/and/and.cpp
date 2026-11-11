#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[20001], b[20001];
vector<long long> c;
bool num[20001][20001];
long long ans, maxx=-1;
void changeNum(){
    for(long long i=0;i<n;i++){
        while(a[i]>0){
            long long p=-1, number=2;
            while(pow(number, p+1)<=a[i]){
                p++;
            }
            num[i][p]=1;
            a[i]-=pow(number, p);
            maxx=max(maxx, p);
        }
    }
}
bool cmp(long long x, long long y){
    return x>y;
}
bool check(long long x){
    for(long long i=0;i<c.size();i++){
        if(c[i]==x) return false;
    }
    return true;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    changeNum();
    long long cnt=0, i, j;
    for(i=maxx;i>=0;i--){
        cnt=0;
        for(j=0;j<n;j++){
            if(num[j][i]==1) cnt++;
        }
        if(cnt>=m){
            for(j=0;j<n;j++){
                if(num[j][i]==1&&check(b[j])) c.push_back(b[j]);
                else for(long long k=maxx;k>=0;k--){
                    num[j][k]=0;
                }
            }
        }
    }
    for(long long i=0;i<m;i++)
    c.push_back(0);
    sort(c.begin(), c.end(), cmp);
    ans=c[0];
    for(int i=1;i<m;i++){
        ans=ans&c[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
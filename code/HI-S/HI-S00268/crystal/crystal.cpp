#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
ifstream cin("crystal.in");
ofstream cout("crystal.out");

long long A[500010];
long long S[500010];
long long SS[500010];
bool cmp(int x,int y);
void solve(int n);

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    solve(n);
    
    cout << endl;
    cin.close();
    cout.close();
    return 0;
}
bool cmp(int x,int y){
    return x<y;
}
void solve(int n){
    long long m,msum=1;
    cin >> m;
    for(int i=1;i<=n;i++)cin >> A[i];
    sort(A+1,A+n+1,cmp);
    for(int i=1;i<=n-1;i++)S[i]=A[i+1]-A[i];//²îÖµ
    for(int i=1;i<=n-1;i++)SS[i]=S[i]+SS[i-1];//Ç°×ººÏ
    //shuang zhizhen
    int i=1,d=1;
    long long sum=1;
    while(i<=d&&i<=n-1&&d<=n-1){
        while(d<=n-1){
            if(m>=(d-i+1)*S[d]){
                m-=(d-i+1)*S[d];
                sum++;
            }
            else{
                break;
            }
            d++;
        }
        msum=max(msum,sum);
        m+=SS[d-1]-SS[i-1];
        i++;
        sum-=1;
    }
    cout << msum;
    return ;
}

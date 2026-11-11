#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
int n,a;
char s,f[N];
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    int total = 0;
    for(int i = 1;i<=n;i++){
        cin>>a>>s;
        for(int j = total+1;j<=total+a;j++){
            f[j]=s;
        }
        total+=a;
    }
    for(int i = 1,j = total;i<j;i++,j--){
        if(f[i]!=f[j]){
            sum++;
        }
    }
    printf("%lld",sum);
    return 0;
}

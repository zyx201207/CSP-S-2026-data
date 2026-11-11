#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=500020;
long long a[maxn];
bool cmp(long long a,long long b){
    return a<b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);

    int maxx=-1;
    long long temp=m;
    for(int i=1;i<=n;i++){
        int cnt=1;
        m=temp;
        for(int j=i-1;j>=1 && m>0;j--){
            int k=a[i]-a[j];
            if(m-k>=0){
                cnt++;
            }
            m-=k;
        }
        if(maxx<cnt){
            maxx=cnt;
        }
    }
    printf("%d",maxx);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

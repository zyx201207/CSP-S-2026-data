#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long n,m;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long mx=-1;
	for(long long i=1;i<=n;i++){
        for(long long j=0;j<=m;j++){
            long long num=a[i]+j;
            long long s=m-j;
            long long cnt=1;
            for(long long k=1;k<=n;k++){
                if(a[k]+s==num){
                    cnt++;
                }
                if(a[k]==num){
                    cnt++;
                }
                if(n-k<mx) break;
            }
            mx=max(mx,cnt);
        }
        if(n-i<mx){
            break;
        }
	}
	cout<<mx<<endl;
	return 0;
}

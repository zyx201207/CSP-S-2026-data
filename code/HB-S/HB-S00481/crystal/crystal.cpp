#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500005],maxn=1;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]) continue;
        int sum=m,cnt=1;
        for(int j=0;j<i;j++){
            if(a[i]-a[j]<sum){
                sum=sum-a[i]+a[j];
                a[j]=a[i];
            }else{
                maxn=i;
                cnt=0;
                break;
            }
        }
        if(cnt==0) break;
    }
    cout<<maxn;
	return 0;
}

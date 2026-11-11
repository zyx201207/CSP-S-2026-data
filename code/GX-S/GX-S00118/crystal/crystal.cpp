#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=5e5+10;
int n;
ull m;
long long a[N];
__int128 cost;
long long cnt=1,maxx;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1,j=2;j<=n;){
		if((cost+cnt*(a[j]-a[j-1]))<=m){
            cost+=cnt*(a[j]-a[j-1]);
			cnt++;
			j++;
		}
		else{
			while((cost+cnt*(a[j]-a[j-1]))>m){
				cost-=(a[j-1]-a[i]);
				i++;
				cnt--;
			}
		}
		maxx=max(cnt,maxx);
	}
	cout<<maxx;
    return 0;
}

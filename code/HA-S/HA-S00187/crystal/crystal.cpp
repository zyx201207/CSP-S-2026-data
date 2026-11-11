#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum=0,y;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int y1=1,y2=1;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		sum=0;
		for (int j=i-1;j>0;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				if(y1<i-j){
					y1=i-j;
				}
				break;
			}
			}
			if(sum<=m){
				y2=i;
			}
		}
	y=max(y1,y2);
	cout<<y;
	return 0;
}

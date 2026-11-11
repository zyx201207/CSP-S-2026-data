#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int maxx=0;
	for(int i=1;i<n;i++){
		int mm=m,cnt=0;
		for(int j=i;j>=0;j--){
			if(mm>=a[i]-a[j]){
				mm-=a[i]-a[j];
				cnt++;
			}else break;
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}

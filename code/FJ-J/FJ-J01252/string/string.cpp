#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n;
long long ans;
pair<int,char> a[N];
int main(){
	ios::sync_with_stdio(false);
	freopen("string.in", "r", stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int l=1,r=n,dl=a[1].first,dr=a[n].first;
	while(l<=r){
		if(dl==dr){
			if(a[l].second!=a[r].second)ans+=dr;
			l++;r--;
			dl=a[l].first,dr=a[r].first;
		}else if(dl>dr){
			dl-=dr;
			if(a[l].second!=a[r].second)ans+=dr;
			r--;dr=a[r].first;
		}else if(dr>dl){
			dr-=dl;
			if(a[l].second!=a[r].second)ans+=dl;
			l++;dl=a[l].first;
		}
	}
	cout<<ans<<endl;
	return 0;
}

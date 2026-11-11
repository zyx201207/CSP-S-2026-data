#include <bits/stdc++.h>
using namespace std;
long long n,b,l=1,r;
bool t=1;
pair<long long,char> a[200010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		if(a[i].second != a[i-1].second && i>=2)t=0;
	}r=n; 
	if(t){
		cout<<0;
		return 0;
	}
	while(l<r){
		if(a[l].second!=a[r].second){
			if(a[l].first>a[r].first){
				b+=a[r].first;
				a[l].first=a[l].first-a[r].first;
				r--;
			}
			else if(a[r].first>a[l].first){
				b+=a[l].first;
				a[r].first=a[r].first-a[l].first;
				l++;
			}
			else{
				b+=a[l].first;
				l++;
				r--;
			}
		}else{
			if(a[l].first>a[r].first){
				a[l].first=a[l].first-a[r].first;
				r--;
			}
			else if(a[r].first>a[l].first){
				a[r].first=a[r].first-a[l].first;
				l++;
			}
			else{
				l++;
				r--;
			}
		}
	}cout<<b;
	return 0;
}

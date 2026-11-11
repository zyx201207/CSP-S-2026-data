#include<bits/stdc++.h>
using namespace std;
long long n,ans;
pair<long long,char> a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long s;
		char c;
		cin>>s>>c;
		a[i]={s,c};
	}
	int l=1,r=n;
	while(l<r){
		int mi=min(a[l].first,a[r].first);
		if(a[l].second==a[r].second){
			if(a[l].first>a[r].first){
				a[l].first-=a[r].first;
				a[r].first=0;
				r--;
			}else if(a[l].first==a[r].first){
				a[l].first=0;
				a[r].first=0;
				l++;
				r--;
			}else{
				a[r].first-=a[l].first;
				a[l].first=0;
				l++;
			}
		}else{
			if(a[l].first>a[r].first){
				a[l].first-=a[r].first;
				a[r].first=0;
				r--;
			}else if(a[l].first==a[r].first){
				a[l].first=0;
				a[r].first=0;
				l++;
				r--;
			}else{
				a[r].first-=a[l].first;
				a[l].first=0;
				l++;
			}
			ans+=mi;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,char>pii;
pii a[100010];
long long sum;
int n,l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}l=1,r=n;
	while(l<r){
		if(a[l].second!=a[r].second){
			sum+=min(a[l].first,a[r].first);
		}
		if(a[l].first>a[r].first){
			a[l].first-=a[r].first;
			r--;
		}
		else if(a[l].first<a[r].first){
			a[r].first-=a[l].first;
			l++;
		}else{
			a[l].first=0,a[r].first=0;
			l++,r--;
		}
	}cout<<sum;
	return 0;
} 

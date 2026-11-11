#include<iostream>
#include<cmath>
using namespace std;
int n;
long long ans;
pair<int,char> a[200100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	for(int i=1,j=n;i<j;){
		if(a[i].first>a[j].first){
			if(a[i].second!=a[j].second) ans+=a[j].first;
			a[i].first-=a[j].first;
			j--;
		}else if(a[i].first<a[j].first){
			if(a[i].second!=a[j].second) ans+=a[i].first;
			a[j].first-=a[i].first;
			i++;
		}else{
			if(a[i].second!=a[j].second) ans+=a[i].first;
			i++;j--;
		}
	}
	cout<<ans;
	return 0;
}

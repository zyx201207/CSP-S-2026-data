#include <bits/stdc++.h>
using namespace std;
string s="";
pair<long long,char>a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	long long sum=0;
	cin>>t;
	scanf("%lld %c",&a[0].first,&a[0].second);
	for(int i=1;i<t;++i){
		scanf("%lld %c",&a[i].first,&a[i].second);
		if(a[i].second==a[i-1].second){
			a[i-1].first+=a[i].first;
			--i,--t;
		}
	}
	for(int i=0,j=t-1;i<j;){
		if(a[i].second==a[j].second){
			if(a[i].first==a[j].first)++i,--j;
			else if(a[i].first>a[j].first)a[i].first-=a[j].first,--j;
			else a[j].first-=a[i].first,++i;
		}
		else{
			if(a[i].first==a[j].first)sum+=a[i].first,++i,--j;
			else if(a[i].first>a[j].first)sum+=a[j].first,a[i].first-=a[j].first,--j;
			else sum+=a[i].first,a[j].first-=a[i].first,++i;
		}
	}
	cout<<sum;
	return 0;
}

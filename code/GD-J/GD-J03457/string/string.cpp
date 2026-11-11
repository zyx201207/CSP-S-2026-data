#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<long long,char> >a;
long long res=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	a.reserve(n);
	for(int i=1;i<=n;i++){
		long long fr;
		char sc;
		scanf("%lld %c",&fr,&sc);
		if(i==1)a.emplace_back(fr,sc);
		else{
			if(sc==a.back().second)a.back().first+=fr;
			else a.emplace_back(fr,sc);
		}
	}
	for(int i=0,j=a.size()-1;i<j;){
		if(a[i].second!=a[j].second)res+=min(a[i].first,a[j].first);
		if(a[i].first>a[j].first)a[i].first-=a[j--].first;
		else if(a[i].first<a[j].first)a[j].first-=a[i++].first;
		else i++,j--;
	}
	printf("%lld",res);
	return 0;
}

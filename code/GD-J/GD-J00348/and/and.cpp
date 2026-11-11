#include<bits/stdc++.h>
using namespace std;
long long ri(){
	long long ans=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar()){}
	for(;isdigit(c);c=getchar())	ans=ans*10+(c^48);
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=ri(),m=ri();
	long long x;
	vector<long long> a;
	for(int i=1;i<=n;i++){
		x=ri();
		auto p=lower_bound(a.begin(),a.end(),x);
		if(p==a.end())	a.push_back(x);
		else{
			if(*p!=x)	a.insert(p,x);
		}
	}
	if(a.size()<m)	cout<<a[0];
	else	cout<<a[a.size()-m];
	return 0;
}
/*
5 3
31 3 1 15 7
*/

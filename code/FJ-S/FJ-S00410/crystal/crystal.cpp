#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010],s[500010];
//FUCK!!!!!!!!!!!!!!!!!!!!!!
bool check(int x){
	vector <int> minst;
	long long minnum=a[x]*x-s[x]+s[0];
	for(int i=1;i<=n-x+1;i++){
		minnum=min(a[i+x-1]*x-s[i+x-1]+s[i-1],minnum);
		if(minnum<=m) return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

bool cmp(long long a,long long b){
	return a<b;
}
vector<long long> a(5e5+10);
vector<long long> s(5e5+10,0);
int chk(int x,long long m){
		int num;
		for(int i=0;i<=x-1;++i){
			if(m+(s[x-1]-s[i])-(x-1-i)*a[x]>=0){
				num=x-i;
				break;
			}
		}
		return num;
}
int main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a.begin()+1,a.begin()+n+1,cmp);
	int k=1;
	while(true){
		if(chk(k,m)>chk(k+1,m)){
			ans=chk(k,m);
			break;
		}
		k++;
	}
	cout<<ans;
	return 0;
}

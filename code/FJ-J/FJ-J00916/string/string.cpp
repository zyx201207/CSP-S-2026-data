#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
#define HMY return
#define pb push_back()
#define pii pair<int,int>
#define N 200005 
signed main(){
	FILE("string")
	int n;
	cin>>n;
	int a[N],b[N],sum=0,ans=0;
	char d[N];
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>d[i];
		sum+=a[i];
		b[i]=b[i-1]+a[i];
	}
	string s;
	s=" "+s;
	int sum2=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s=s+d[i];
			//sum2++;
			//cerr<<i<<"\n";
		}
		//cerr<<sum2<<'\n';
	}
	//cerr<<"Hello!";
	int i=1,j=s.length()-1;
	while(i<=j){
		if(s[i]!=s[j]) ans++;
		i++,j--;
	}
	cout<<ans<<'\n';
	HMY 0;
}
//T2
//n<=2*10^5
//O(nlogn) ?
//9:02
//lower-bound
//ÓÐ²ÐÓàÔõÃ´°ì ???
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/ 

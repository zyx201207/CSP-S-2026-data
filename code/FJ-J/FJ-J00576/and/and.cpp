#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5; 
long long n,m;
struct P{
	long long a;
	//string b;
}p[N];
vector<long long> cnt[32]; 
bool cmp(P aa,P bb){
	return  aa.a>bb.a;
}

void find(long long x,long long p){
//	string s="";
	int sum=0;
	while(x){
	//	s+=(x%2+('0'));
		if(x%2){
			cnt[sum].push_back(p);
		}
		x=x/2;
		sum++;
	}
//	reverse(s.begin(),s.end());	
	return ;
}
void solve6(){
	long long maxn=-1; 
	for(int i=1;i<=n;i++){
		maxn=max(maxn,p[i].a);
	} 
	cout<<maxn;
	cout<<endl;
	return ;
}
void solve7(){
	long long maxn=p[1].a;
	for(int i=2;i<=n;i++){
		maxn=(maxn&p[i].a);
	}
	cout<<maxn;
	cout<<endl;
	return ;
}
signed main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>p[i].a;
//cout<<a[i]<<" ";
}
sort(p+1,p+n+1,cmp);
for(int i=1;i<=n;i++){
	find(p[i].a,p[i].a);
}
/*
//cout<<"\n";
*/
if(n<=2000&&m==1){
	solve6();
	return 0;}
if(n<=2000&&m==n){
	solve7();
	return 0;
}
/*for(int i=1;i<=n;i++){
	cout<<p[i].a<<" "<<p[i].b<<"\n";
}*/
/*for(int i=31;i>=0;i--){
	cout<<cnt[i].size();
}
cout<<"\n";
*/
for(int i=31;i>=0;i--){
	if(cnt[i].size()>=m){
		vector<long long> ok;
		ok.clear(); 
		for(long long p:cnt[i]){
		ok.push_back(p);
		}
		vector<long long> ok2;
		int pos=i-1;
		ok2.clear();
		while(ok.size()>=m&&pos>=0){
		for(long long p:ok){
			if(p&(1<<pos)){
				ok2.push_back(p);
			}
		}
		if(ok2.size()<m){
			long long ans=ok[0];
			for(int i=1;i<m;i++){
				ans=ans&ok[i];
			}
			cout<<ans;
			cout<<endl;
			return 0;
		}
		ok=ok2;
		ok2.clear();
		pos--;
	}
	long long ans=ok[0];
	for(int i=1;i<m;i++){
		ans=ans&ok[i];
	}
	cout<<ans;
	cout<<endl;
	return 0;
}
}
cout<<0;
cout<<endl;
return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int Max=1e9;
const long long lMax=1e18;
struct stu{
	long long x;
	char c;
}a[N];
vector<pair<int,char> > v1,v2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long n;
	cin>>n;
	string s;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		for(int j=1;j<=a[i].x;j++){
			s+=a[i].c;
		}
		sum+=a[i].x;
	}
	long long ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	/*
	long long jo=-1;
	if(sum%2==0) jo=0;
	else jo=1;
	long long p=sum/2,k=0,f=-1;
	for(int i=1;i<=n;i++){
		k+=a[i].x;
		if(k>=p){
			f=i;
			break;
		}
	}
	for(int i=1;i<f;i++){
		v1.push_back(make_pair(a[i].x,a[i].c));
	}
	if(v1.size()<=p){
		v1.push_back(make_pair(p-v.size(),a[f].c);
		v2.push_back(make_pair(a[f].x-(p-v.size())-jo,a[f].c));
	}
	for(int i=f+1;i<=n;i++){
		v2.push_back(make_pair(a[i].x,a[i].c));
	}
	*/
	
	return 0;
}

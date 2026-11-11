#include<bits/stdc++.h>
using namespace std;
//
long long n,m;
vector<long long> v(5e5+100),d(5e5+100),s1(5e5+100),s2(5e5+100);
bool check(long long len){
	if(len==1){
		return 1;
	}
	bool is_b=0;
	for(long long i=0;i+len<=n;i++){
		long long cnt=(len-1)*(s1[i-2+len])-(i-3+len<0?0:s2[i-3+len])+(i-2<0?0:s2[i-2]);
//		for(long long j=i;j<i+len-1;j++){
//			cnt+=d[j]*(j-i+1);
//		}
		if(cnt<=m){
			is_b=1;
			break;
		}
	}
	return is_b;
}
//
int main(){
	ifstream in("crystal.in");
	ofstream out("crystal.out");
	//
	in>>n>>m;
	for(long long i=0;i<n;i++){
		in>>v[i];
	}
	sort(v.begin(),v.begin()+n);
	for(long long i=0;i<n-1;i++){
		d[i]=v[i+1]-v[i];
	}
	s1[0]=d[0];
	s2[0]=d[0];
	for(long long i=1;i<n-1;i++){
		s1[i]=s1[i-1]+d[i];
		s2[i]=s2[i-1]+s1[i];
	}
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r+1)>>1;
//		cout<<mid<<'\n';
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	out<<l;
	return 0;
}

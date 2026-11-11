#include<bits/stdc++.h>
using namespace std;
struct kx{
	long long start,end;
};
long long n,m,best=2;
long long xq(vector<long long>& s,long long start1,long long end1,long long sum,long long q){
	if(sum<=m) return end1-start1+1;
	long long kh=q*(s[end1]-s[end1-1]),kq=s[end1]-s[start1];
	return max(xq(s,start1+1,end1,sum-kq,q-1),xq(s,start1,end1-1,sum-kh,q-1));
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long> s(n,0);
	for(long long i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s.begin(),s.end());
	kx a[n];
	long long be=0,id=0;
	bool t=false;
	for(long long i=1;i<n;i++){
		if(s[i]-s[i-1]>m){
			a[id].start=be;
			a[id++].end=i-1;
			be=i;
			t=true;
		}
	}
	if(!t){
		a[id].start=be;
		a[id++].end=n-1;
	}
	for(long long i=0;i<id;i++){
		long long q=a[i].end-a[i].start,sum=0;
		for(long long j=0;j<q;j++){
			sum+=(s[a[i].end]-s[a[i].start+j]);
		}
		best=max(best,xq(s,a[i].start,a[i].end,sum,q));
	}
	cout<<best;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


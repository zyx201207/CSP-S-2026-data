#include <bits/stdc++.h>
using namespace std;
const long long N=2*1e5+5;
long long unsigned n,m,r,mmax=-99999,dd[N];
struct xry{
	long long a;
	bool flag=1;
	string s;
}p[N];
bool cmp(xry x,xry y){
	if (x.a<y.a) return x.a<y.a;
}
void change(long long x){
	r=0;
	while (x!=0){
		p[r].s+=(x%2)+'0';
		x/=2;
		r++;
	}
	mmax=max(mmax,r);
}
int main(){
	cin>>n>>m;
	for (long long unsigned i=0;i<n;i++){
		cin>>p[i].a;
		change(p[i].a);
	}
	sort(p,p+n,cmp);
	for (long long unsigned i=0;i<n;i++){
		if (p[i].s.size()!=mmax){
			string s2="";
			for (long long unsigned j=0;j<(mmax-p[i].s.size());j++) s2+="0";
			p[i].s=s2+p[i].s;
		}
	}
	long long unsigned cnt=0;
	for (long long unsigned i=0;i<mmax;i++){
		if (cnt!=m){
			for (long long unsigned j=0;j<n;j++) p[j].flag=1;
			cnt=0;
		}
		else break;
		for (long long unsigned j=0;j<n;j++){
			if (p[j].s[i]==1&&p[j].a!=-1){
				p[j].flag=0;
				 if (p[j].a!=p[j+1].a) cnt++;
			}
			else p[j].a=-1;
		}
	}
	string zh[N];
	int z=0;
	for (long long unsigned i=0;i<n;i++){
		if (p[i].a!=-1){
			zh[z]=p[i].s;
			z++;
		}
	}
	for (long long unsigned i=0;i<z;i++){
		for (long long unsigned j=0;j<mmax;j++){
			if (zh[i][j]=='1') dd[j]++;
		}
	}
	string ss="";
	for (long long unsigned i=0;i<mmax;i++){
		if (dd[i]==z) ss+='1';
		else ss+='0';
	}
	long long unsigned zz=0;
	int aa=0;
	for (long long unsigned i=s.size()-1;i>=0;i--){
		zz+=pow((ss[i]-'0'),aa*2);
	}
	cout<<zz;
	return 0;
}

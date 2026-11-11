#include <bits/stdc++.h>
using namespace std;
string exc(long long n){
	string s="";
	long long m=n;
	while(m){
		if(m%2==0){
			s="0"+s;
		}else s="1"+s;
		m/=2;
	}
	return s;
}
struct node{
	string s;
	long long a;
}t[200010];
long long p[40],maxw=-1;
long long count(string a){
	long long cnt=0;
	for(long long i=0;i<a.size();i++){
		if(a[i]=='1')cnt++;
	}return cnt;
}bool cmp(node a,node b){
	long long a1=count(a.s),b1=count(b.s);
	if(a1==b1)return a.s>b.s;
	return a1>b1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>t[i].a;
		t[i].s=exc(t[i].a);
		p[count(t[i].s)]++;
		maxw=max(maxw,count(t[i].s));
	}for(long long i=maxw;i>=1;i--){
		if(p[i]>=m){
			maxw=i;
			break;
		}
	}for(long long i=0;i<n;i++){
		if(t[i].s.size()>maxw){
			t[i].s.replace(0,t[i].s.size()-maxw,"");
		}
	}sort(t,t+n,cmp);
	long long ans=t[0].a;
	for(long long i=1;i<m;i++){
		ans&=t[i].a;
	}cout<<ans;
	return 0;
}

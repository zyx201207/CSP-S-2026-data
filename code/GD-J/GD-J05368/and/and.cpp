#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

int n,m,ans;

struct t{
	int s1;
	string s;
	int len,sum;
}a[200005];

string to(int y){
	string result="";
	while(y>0){
		result=result+(char)(y%2);
		y/=2;
	}
	return result;
}

int h(string y){
	int num=0;
	for(int i=0;i<y.size();i++){
		if(y[i]=='1') num++;
	}
	return num;
}

bool cmp(t x,t y){
	if(x.len>y.len) return 1;
	if(x.sum>y.sum) return 1;
	return 0;
}

int bj(int k,int l){
	string h=to(k);
	string j=to(l);
	string r="";
	for(int i=1;i<=max(h.size(),j.size());i++){
		r=r+(h[i] and j[i]);
	}
	int i=1,ans=0;
	for(int i=r.size()-1;i>=0;i++){
		ans+=r[i]*i;
		i*=2;
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1;
		a[i].s=to(a[i].s1);
		a[i].len=a[i].s.length();
		a[i].sum=h(a[i].s);
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].s1;
	for(int i=2;i<m;i++){
		ans=bj(ans,a[i].s1);
	}
	cout<<ans;
	return 0;
}
int main(){
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
string s[200005];
bool cmp(string a,string b){
	int o1=0,o2=0;
	for(int l=0; l<a.size(); l++){
		if(a[l]=='1')o1++;
	}
	for(int l=0; l<b.size(); l++){
		if(b[l]=='1')o2++;
	}
	return o1>o2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int l=1; l<=n; l++){
		cin>>a[l];
		while(a[l]!=0){
			s[l]=s[l]+char(a[l]%2+'0');
			a[l]=a[l]/2;
		}
	}
	sort(s+1,s+n+1,cmp);
	int d=INT_MIN;
	for(int l=1; l<=m; l++){
		d=max(d,int(s[l].size()));
	}
	int cnt=0,c=1;
	string t="";
	for(int l=0; l<d; l++){
		int pd=1;
		for(int k=1; k<=m; k++){
			if(s[k].size()<=l){
				pd=0;
				break;
			}
			if(s[k][l]=='0'){
				pd=0;
				break;
			}
		}
		t=char(pd+'0')+t;
	}
	for(int l=0; l<t.size(); l++){
		if(t[l]=='1')cnt=cnt+c;
		c=c*2;
	}
	cout<<cnt;
}

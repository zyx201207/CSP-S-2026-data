#include<bits/stdc++.h>
using namespace std;
struct node{
	int b;
	char s;
}a[200005];
int n;
string add(string x,string y){
	int c[100005]={},d[100005]={},e[100005]={};
	for(int i=max(x.size(),y.size())-x.size();i<max(x.size(),y.size());i++){
		c[i+1]=x[i-max(x.size(),y.size())+x.size()]-'0';
	}
	for(int i=max(x.size(),y.size())-y.size();i<max(x.size(),y.size());i++){
		d[i+1]=y[i-max(x.size(),y.size())+y.size()]-'0';
	}
	int xx=0;
	for(int i=max(x.size(),y.size());i>=1;i--){
		e[i]=d[i]+c[i]+xx;
		if(e[i]>=10){
			xx=e[i]/10;
			e[i]%=10;
		}
	}
	e[0]=xx;
	string yy="";
	if(xx==0){
		for(int i=1;i<=max(x.size(),y.size());i++){
			yy=yy+char(e[i]+'0');
		}
	}
	else{
		for(int i=0;i<=max(x.size(),y.size());i++){
			yy=yy+char(e[i]+'0');
		}
	}
	return yy;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].b>>a[i].s;
	}
	if(n==1){
		cout<<0;
	}
	else if(n==2){
		if(a[1].s==a[2].s){
			cout<<0;
		}
		else{
			cout<<min(a[1].b,a[2].b);
		}
	}
	else{
		int l=1,r=n;
		string ans="0";
		while(l<r){
			if(a[l].b<=a[r].b){
				if(a[l].s!=a[r].s){
					ans=add(ans,to_string(a[l].b));
				}
				a[r].b-=a[l].b;
				l++;
				if(a[r].b==0){
					r--;
				} 
			}
			else{
				if(a[l].s!=a[r].s){
					ans=add(ans,to_string(a[r].b));
				}
				a[l].b-=a[r].b;
				r--;
				if(a[l].b==0){
					l++;
				}
			}
		}
		cout<<ans; 
	}
	return 0;
}

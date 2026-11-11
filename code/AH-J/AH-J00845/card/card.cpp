#include <bits/stdc++.h>
using namespace std;
string a[500005];
int b[300005];
string abc(int sum){
	string s="";
	while(sum>0){
		char c=(sum%10+'0');
		s=c+s;
		sum/=10;
	}
	return s;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=-1;i<n-1;++i){
		string s="";
		for(int j=i+1;j<n;++j){
			int y=s.find((a[j]+" "));
			if(y!=-1)s=s.substr(0,y);
			s+=a[j]+" ";
		}
		for(int j=1;j<=m;++j){
			string f=abc(j);
			if(s.find(f)!=-1)b[j]++;
		}
	}
	for(int i=1;i<=m;++i)cout<<b[i]<<' ';
	return 0;
}

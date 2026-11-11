#include<bits/stdc++.h>
using namespace std;
long long a[200001],c[200001];
string b[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[n-i+1]=a[i];
	}
	for(int i=1;i<=n;i++){
		long long t=c[i];
		b[i]="";
		while(t){
			int g=t%2;
			b[i]+=(g+48);
			t=t/2;
		}
		reverse(b[i].begin(),b[i].end());
		if(b[i].size()>max) max=b[i].size();
	}
	string s;
	for(int i=1;i<=max;i++){
		s=s+"1";
	}
	for(int i=1;i<=m;i++){
		string g=b[i];
		for(int j=0;j<g.size();j++){
			if(g[j]=='0'){
				s[j]='0';
			}
		}
	}
	int y=0;
	for(int i=max-1;i>=0;i--){
		y=y+(int(s[i])-48)*pow(2,max-i-1);
	}
	cout<<y;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

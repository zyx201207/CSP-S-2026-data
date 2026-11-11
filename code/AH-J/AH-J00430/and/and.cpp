#include<bits/stdc++.h>
using namespace std;
long long n,m,k=0,d[200005]={0};
string a[200005];
bool cmp(string x,string y){
	for(int i=0;i<k;i++){
		if(x[i]!=y[i]) return x>y;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long t,sum=0,i=1;
	for(int i=1;i<=n;i++){
		sum=0;
		cin>>t;
		while(t>0){
			char y=(t%2+'0');
			a[i]=y+a[i];
			t/=2;
			sum++;
		}
		k=max(k,sum);
	}
	
	long long b[k+5]={0};
	for(int i=1;i<=n;i++){
		if(a[i].size()<k){
			string x="";
			for(int j=1;j<=k-a[i].size();j++){
				x+="0";
			}
			a[i]=x+a[i];
		}
	}
	
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		string x=a[i];
		for(int j=0;j<x.size();j++){
			if(x[j]=='1'){
				b[j+1]++;
			}
		}
	}
	string y="";
	for(int i=1;i<=k;i++){
		if(b[i]==m){
			y+="1";
		}else{
			y+="0";
		}
	}
	long long ans=0,c=1;
	for(int i=y.size()-1;i>=0;i--){
		if(y[i]=='1'){
			ans+=c;
		}
		c*=2;
	}
	cout<<ans;
	return 0;
}

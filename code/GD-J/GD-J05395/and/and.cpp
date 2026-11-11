#include <bits/stdc++.h>
using namespace std;
string tun(int k){
	string p;
	while(k!=0){
		if(k%2==1){
			p+="1";
		}else{
			p+="0";
		}
		k/=2;
	}
	reverse(p.begin(),p.end());
	return p;
}
bool cmp(string a,string b){
	int flag=0;
	for(int j=29;j>=0;j--){
		if(a[j]=='1'&&b[j]=='0')return a>b;
		if(a[j]=='1'&&b[j]=='1'){
			continue;
		}
		if(a[j]=='0'&&b[j]=='1')return a<b;
	}
}
int a[200005];
string r[200005],l[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
		r[i]=tun(a[i]);
		l[i]=r[i];
		reverse(r[i].begin(),r[i].end());
		for(int j=0;j<30-r[i].size();j++){
			r[i]+="0";
		}
		reverse(r[i].begin(),r[i].end());
	}
	sort(r+1,r+n+1,cmp);
	string y=r[1];
	for(int j=2;j<=m;j++){
		string w=r[j];
		string k="";
		for(int i=29;i>=0;i--){
			if(y[i]=='1'&&w[i]=='1'){
				k+="1";
			}else{
				k+="0";
			}
		}
		y=k;
		int uo=0;
		for(int k1=29;k1>=0;k1--){
			uo+=(int)s[k1]*pow(2,k1);
		}
	} 
	cout<<uo<<endl;
	return 0;
} 

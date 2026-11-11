#include<bits/stdc++.h>
using namespace std;
long long n,a[100000],b[10000],sum,m,z=INT_MIN;
string cnt(int n){
	string s="";
	while (n){
		if(n%2==0){
			s+="0";
		}else if(n%2==1){
			s+="1";
		}
		n/=2;
	}
	string c;
	for(int i=s.size()-1;i>=0;i--){
		c+=s[i];
	}
	return c;
}
string man(long long x,long long y){
	string sum="";
	string x1=cnt(x),y1=cnt(y);
	if(x1==y1){
		return x1;
	}
	long long xo=x1.size(),yo=y1.size();
	long long l=min(x1.size(),y1.size());
	for(int i=1;i<=l;i++){
		if(x1[--xo]=='1'&&y1[--yo]=='1'){
			sum+="1";
		}else{
			sum+="0";
		}
	}
	string c;
	for(long long i=sum.size()-1;i>=0;i--){
		c+=sum[i];
	}
	return c;
}
long long ysnb(long long x,long long y){
	long long ans=0;
	long long w=0;
	string op=man(x,y);
	long long l=op.size();
	for(long long i=l-1;i>=0;i--){
		if(op[i]=='1'){
			ans+=1*pow(2,w);
		}
		w++;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(z<ysnb(a[i],a[j])){
				z=ysnb(a[i],a[j]);
			}
		}
	}
	cout<<z;
	return 0;
} 

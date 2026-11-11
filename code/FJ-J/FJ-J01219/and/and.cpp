#include <bits/stdc++.h>
using namespace std;
string erjin(long long n){
	long long a=n;
	int j=0;
	string s="00000000";
	while(n>0){
		while(a>0){
			a/=2;
			j++;
		}
		s[j-1]='1';
		n-=pow(2,j-1);
		j=0;
		a=n;
	}
	return s;
}
long long anwei(string a,string b){
	long long num;
	for(int i=1;i<=8;i++){
		if(a[i]==b[i] && a[i]=='1'){
			num+=pow(2,i-1);
		}
	}
	return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],max_=0;
	string b[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max_=max(a[i],max_);
	}
	if(m==1){
		cout<<max_;
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i]=erjin(a[i]);
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=m;j++){
				max_=max(max_,anwei(b[i],b[j]));
			}
		}
		cout<<max_;
		return 0;
	}

	return 0;
}

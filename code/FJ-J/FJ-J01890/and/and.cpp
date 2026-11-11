#include<bits/stdc++.h>
using namespace std;
int a[200200];
string b[200200];
int jz(int x){
	int y=x;
	if(x==0){
		return 0;
	}
	int s=0;
	int t=0;
	while(x!=0){
		t=x%2;
		s+=t*10;
		s*=10;
		x/=2;
	}
	while(y){
		if(y==2){
			break;
		}
		if(y/2==2){
			return 10*s;
		}
		y/=2;
	}
	return s;
}
int th(string x,string y){
	string k="";
	for(int i=max(x.size(),y.size());i>=1;i--){
		if(x[i]==y[i]){
			k+='1';
		}else{
			k+='0';
		}
	}
	int s;
	for(int i=0;i<=k.size()-1;i++){
		s+=k[i]-'0';
		s*=10;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=jz(a[i])+'0';
	}
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;i++){
			if(i==j){
				continue;
			}
			s=max(s,th(b[i],b[j]));
		}
	}
	cout<<s;
	return 0;
}

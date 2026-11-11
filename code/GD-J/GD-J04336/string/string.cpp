#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
ll n;
ll xx,v=0;
int b[26]; 
char yy;
string a;
int f=0,zz=0,cc=0,cs=0,zs=100000009;
void ff(char x,ll s){
	for(int i=s;i<=v;i++){
		if(a[i]==x)break;
		cs++;
		a[i]=x;
		string dsb;
		for(int i=a.size();i>1;i--){
			dsb[i]=a[i];
		}
		if(dsb==a){
			zs=min(cs,zs);
		}else{
			ff(x,s+1);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cin>>xx>>yy;
		b[int(yy-'a')]+=xx;
		for(int j=v;j<=xx+v;j++){
			a[j]=yy;
		}
		v+=xx;
	}
	//for(int i=0;i<26;i++){
	//	cout<<b[i];
	//}
	for(int i=0;i<25;i++){
		zz=f;
		f=max(b[i],b[i+1]);
		if(f!=zz){
			cc=i;
		}
	}
	if(v==a[cc]){
		cout<<"0";
		return 0;
	} 
	char hh=cc+'a';
	ll jj=0;
	ff(hh,jj);
	cout<<zs;
	return 0;
} 

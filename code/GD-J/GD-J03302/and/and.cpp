//WA
#include<bits/stdc++.h>
using namespace std;
int m,n,a[100005],x,k,l[100005];
void revout(string s){
	for(int i=s.length()-1;i>=0;i--){
		cout<<s[i];
	}
	cout<<endl;
}
string change10to2r(int p){
	string w;
	while(p>0){
		if(p%2)w+='1';
		else w+='0';
		p/=2;
	}
	return w;
}
string yur(string d,string f){
	string g;
	if(d.length()>f.length()){
		g=d;
		d=f;
		f=g;
	}
	g="";
	for(int i=0;i<d.length();i++){
		if(d[i]=='1'&&f[i]=='1'){
			g+='1';
		}
		else{
			g+='0';
		}
	}
	return g;
}
int change2rto10(string r){
	int t=0,u=1;
	for(int i=0;i<r.length();i++){
		if(r[i]=='1'){
			t+=u;
		}
		u*=2;
	}
	return t;
}
void ac(int i[]){
	string j[n];
	for(int p=0;p<n;p++){
		j[p]=change10to2r(i[p]);
		//revout(j[p]);
	}
	for(int p=1;p<n;p++){
		j[p]=yur(j[p-1],j[p]);
	}
	int q=change2rto10(j[n-1]);
	if(q>m){
		m=q;
	}
}
void xunhuan(int i){
	++k;
	if(k>n){
		ac(l);
		for(int i=0;i<100005;i++){
			l[i]=0;
		}
	}
	else{
		l[k-1]=i;
		for(int j=i;j<x-(n-k);j++){
			cout<<i<<" "<<j<<endl;
			xunhuan(j);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>x>>n;
	for(int i=0;i<x;i++){
		cin>>a[i];
	}
	//xunhuan(0);
	for(int i=0;i<x-1;i++){
		for(int j=1;j<x;j++){
			string i1=change10to2r(a[i]);
			string j1=change10to2r(a[j]);
			string w=yur(i1,j1);
			int q=change2rto10(w);
			if(q>m){
				m=q;
			}
		}
	}
	cout<<m;
	return 0;
} 

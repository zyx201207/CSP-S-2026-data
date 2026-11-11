#include<bits/stdc++.h>
using namespace std;
int n;
char f[200009];
long long a[200009];
string x,y;
string s;
long long ans;
int gcd(int cx,int cy){
	if(cy==0){
		return cx;
	}
	int az=cx%cy;
	return gcd(cy,az);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> f[i];
	}
	int ghp=a[1];
	for(int i=2;i<=n;i++){
		ghp=gcd(ghp,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i]/ghp;j++){
			s+=f[i];
		}
	}
	int gl=s.size();
	for(int i=0;i<gl/2;i++){
		x+=s[i];
	}
	if(gl%2==0){
		gl/=2;
		gl--;
	}else{
		gl/=2;
	}
	for(int i=s.size()-1;i>gl;i--){
		y+=s[i];
	}
	int xc=x.size();
	for(int i=0;i<xc;i++){
		if(x[i]!=y[i]){
			ans++;
		}
	}
	cout<<ans*ghp;
	return 0;
}

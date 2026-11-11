#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	long long n,a[200004],x,y,jg=0;
	string c,s,e,f;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	x=s.size();
	for(int i=x;i>x/2;i--){
		e+=s[i-1];
		f+=s[x-i];
	}
	y=e.size();
	for(int i=0;i<y;i++){
		if(e[i]!=f[i]){
			jg++;
		}
	}
	cout<<jg;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


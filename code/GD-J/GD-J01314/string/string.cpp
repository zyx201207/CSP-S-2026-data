#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans,sum;
string s;
string reverse(string x){
	string y="";
	for(int i=x.size()-1;i>=0;i--) y+=x[i];
	return y;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char ch;
		scanf("%d%c%c",&a[i],&ch,&c[i]);
		for(int j=1;j<=a[i];j++) s+=c[i];
		sum+=a[i];
	}
	string f,b;
	if(sum%2==1){
		f=s.substr(0,s.size()/2);
		b=s.substr(s.size()/2+1);
	}
	else{
		f=s.substr(0,s.size()/2);
		b=s.substr(s.size()/2+1);
	}
	string f1=reverse(f);
	for(int i=0;i<f1.size();i++){
		if(f1[i]!=b[i]) ans++;
	}
	cout<<ans;
	return 0;
}

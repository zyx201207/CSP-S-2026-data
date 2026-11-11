#include<bits/stdc++.h>
using namespace std;
int n,p,ans;
string s; 
struct w{
	int a;
	char b;
}a[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		cin>>a[i].b;
		for(int j=1;j<=a[i].a;j++){
			s=s+a[i].b;
		}
	}
	p=s.size();
	if(p%2!=0){
		p+=1;	
		p=p/2-1;
	}
	else{
		p=p/2;
	}
	int j=s.size()-1;
	for(int i=0;i<p;i++){
		char a1=s[i];
		char a2=s[j];
		if(a1!=a2){
			ans++;
		}
		j--;
	}
	cout<<ans;
	return 0;
}

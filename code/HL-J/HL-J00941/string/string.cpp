#include<bits/stdc++.h>
using namespace std;	
string s;
void f(int a,string d){
	for(int i=0;i<a;i++){
		s+=d;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string p;
	int a;
	for(int i=0;i<n;i++){
		cin>>a>>p;
		f(a,p);
	}
	int ct=s.size();
	int ans=0;//xiugai...
	if(ct%2==0){
		for(int i=0;i<ct/2-1;i++){
			for(int j=ct-1;j>=ct/2;j--){
				if(s[i]!=s[j])ans++;
			}
		}
	}
	else{
		for(int i=0;i<ct/2-1;i++){
			for(int j=ct-1;j>=ct/2+1;j--){
				if(s[i]!=s[j])ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}


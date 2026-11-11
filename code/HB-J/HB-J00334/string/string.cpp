#include <bits/stdc++.h>
using namespace std;
bool check(string s){
	int flag=0;
	int n=s.size();
	for(int i=0;i<n/2;i++){
		for(int j=n-1;j>n/2;j--){
			if(s[i]!=s[j]){
				flag=1;
			}
		}
	}
	if(flag==0){
		return true;
	}
	else{
		return false;
	}
}
long long x[200005];
char y[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>x[i];
		cin>>y[i];
	}
	int flag=0;
	for(int i=0;i<n-1;i++){
		if(x[i]!=x[i+1]){
			flag=1;
		}
	}
	int flag2=0;
	if(flag==0){
		for(int i=0;i<n;i++){
			s=s+y[i];
		}
		flag2=1;
	}
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<x[i];j++){
				s=s+y[i];
			}
		}
	}
	cout<<s<<endl;
	long long ans=0;
	long long h=s.size();
	if(check(s)==true){
		cout<<0;
		return 0;
	}
	else {
		for(int i=0;i<h/2;i++){
			for(int j=h-1;j>h/2;j--){
				if(s[i]!=s[j]){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	if(flag2==1){
		ans=ans*x[0];
	}
	cout<<ans/2;
	return 0;
}

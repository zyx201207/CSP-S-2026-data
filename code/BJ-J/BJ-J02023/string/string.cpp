#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int h[5005];
	char f[5005];
	string s;
	for(int i=0;i<=n;i++){
		cin>>h[i]>>f[i];
		for(int j=0;j<h[i];j++){
			s+=f[i];
		}
	}
	int a=s.size()/2+1,b=s.size();
	string s1;
	for(int i=a;i>0;i--){
		s1+=s[i];
	}
	int sum=0;
	for(int i=a;i<b;i++){
		if(s1[i]!=s[i]){
			sum++;
		}
	}
	cout<<sum;
}

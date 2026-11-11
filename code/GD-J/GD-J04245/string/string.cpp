#include<iostream>
using namespace std;
char c[60000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0;
	cin>>n;
	int a;
	char b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int i=0;i<a;i++){c[l]=b;l++;}
	}
	int ans=0;
	for(int i=0;i<(l-1)/2;i++){
		if(c[i]!=c[l-i-1])ans++;
	}
	cout<<ans;
}

#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	string s1;
	char c1;
	long long js=0,js1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>c1;
		js1=js;
		while(js<js1+m){
			s1[js++]=c1;
		}
	}
	int l=0,r=js-1,ans=0;
	while (l<=r){
		if(s1[l++]!=s1[r--])ans++;
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long ans=0;
vector<char> s;
vector<int> a;
string c;
bool f(string a){
	string b;
	for(int i=a.size()-1;i>=0;i--)b[i]=a[i];
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i])return 0;
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin>>n;
	for(int i=0;i<n;i++){ 
		cin>>a[i]>>s[i];
	} 
	for(int i=0;i<n;i++){ 
		int x=a[i];
		for(int j=0;j<=x;j++)c.push_back(s[i]);
	} 
	if(f(c)!=0)ans+=0;
	else{
		 
	}
	cout<<ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

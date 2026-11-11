#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[100005];
char c[100005];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s = "";
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	
	long long l = 0;
	long long r = s.size() - 1;
	
	while(l < r){
		if(s[l] != s[r]){
			ans++;
		}
		l++;
		r--;
	}
	
	cout<<ans;
	
	return 0;
}

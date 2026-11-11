#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int a[200005];
	char c[200005];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++) s+=c[i];	
	}
	int m=s.size();
	long long sum=0;
	for(int i=0;i<=m/2;i++){
		if(s[i]!=s[m-i-1]){
			sum++;
		} 
	}
	cout<<sum;
	return 0;
}

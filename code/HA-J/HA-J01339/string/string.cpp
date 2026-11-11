#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,lo=0,count=0;
	string c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
			lo+=1;
		}
	}
	for(int i=0;i<lo/2;i++){
		if(s[i]!=s[lo-i-1]){
			count++;
		}
	}
	cout<<count;
	return 0;
}

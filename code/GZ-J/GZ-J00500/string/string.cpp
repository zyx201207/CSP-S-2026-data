//GZ-J00500 遵义市第十二中学 梅东耀 
#include<bits/stdc++.h>
using namespace std;
int hw(string x){
	long long ans=0,len=x.size(),j=0;
	if(len<2) return ans;
	string a="",b="";
	for(long long i=0;i<len/2;i++){
		a[j]+=x[i];
		b[j]+=x[len-i-1];
		j++;
	}
	for(long long i=0;i<j;i++){
		if(a[i]!=b[i]) ans++;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n;
	string s="";
	char c;
	for(int i=0;i<n;i++){
		cin>>m>>c;
		for(int j=0;j<m;j++) s+=c;
	}
	cout<<hw(s);
	return 0;
}

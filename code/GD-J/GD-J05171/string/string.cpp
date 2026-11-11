#include<bits/stdc++.h>
using namespace std;
int a[100000001];
char c[200001];
bool hwc(string s){
	string k=s;
	int l=s.length();
	for(int i=0;i<l/2;i++){
		swap(s[i],s[l-i-1]);
	}
	return k==s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(hwc(s)){
		cnt=0;
	}
	else{
		cnt=s.length()/2;
	}
	cout<<cnt<<endl;
	return 0;
}

//GZ-J00147 贵阳市南明区华麟学校 蒋定奚
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	cin>>n;
	int a[n];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	bool t=true;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			t=false;
		}
	}
	if(t){
		cout<<0;
		return 0;
	}
	int sum=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			sum++;
		}
	}
	cout<<sum;

	return 0;
}

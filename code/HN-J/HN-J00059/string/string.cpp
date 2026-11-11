#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int a;
	cin>>a;
	int b[100000];
	char c;
	string s,t;
	for(int i=0;i<a;i++){
		cin>>b[i];
		cin>>c;
		for(int z=0;z<b[i];z++){
			s+=c;
		}
	}
	int ans=0;
	int j=s.size();
	for(int i=0;i<j/2;i++){
		if(s[i]!=s[j-i-1]){
			ans++;
		}
	}
	cout<<ans;
}

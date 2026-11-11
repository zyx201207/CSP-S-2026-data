#include<bits/stdc++.h>
using namespace std;
string c[10000000];
int m[10000000];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	string s="";
	cin >> n;
	if(n==1){
		cout << cnt;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin >> m[i] >> c[i];
		for(int j=0;j<m[i];j++){
			s+=c[i];
		}
	}
	if(n==2){
		if(c[0]==c[1]){
			cout << cnt;
			return 0;
		}else if(m[0]==m[1]){
			cout << m[0];
			return 0;
		}else if(m[0]<m[1]){
			cout << m[0];
			return 0;
		}else if(m[0]>m[1]){
			cout << m[1];
			return 0;
		}
	}
	for(int i=0;i<s.length/2;i++){
		if(s[i]==s[s.length-1-i]){
			continue;
		}else{
			cnt++;
		}
	}
	cout << cnt;
		
	return 0;
}

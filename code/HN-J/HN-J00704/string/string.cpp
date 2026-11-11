#include<bits/stdc++.h>
using namespace std;
int n,k;
void hw(string s){
	int d=s.size();
	for(int i=0;i<=d/2;i++){
		if(s[i]!=s[d-i-1]) k++;
	}
	cout<<k;
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	hw(s);
	return 0;
} 

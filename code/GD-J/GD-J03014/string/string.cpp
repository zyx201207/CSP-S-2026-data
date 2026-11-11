#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i,p,cnt=0;
	cin>>i;
	string s=" ";
	for(int j=1;j<=i;j++){
		cin>>p;
		char c;
		cin>>c;
		
		for(int k=1;k<=p;k++){
			s+=c;
		}
	}
	long long z=s.size();
	for(long long q=1;q<=z/2;q++){
		if(s[q]!=s[z-q]){
			s[z-q]=s[q];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
	
}




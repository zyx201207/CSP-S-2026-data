#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	string s;
	int n;
	cin>>n;
	long long q=0,y=0;
	for(int i=1;i<=n;i++){
		long long a;
		char p;
		cin>>a>>p; 
		for(long long j=1;j<=a;j++){
			q++;
			s[q]=p;
			
		}	
	}
	for(long long i=1;i<=q/2;i++){
		if(s[i]!=s[q-i+1]){
			y++;
		}
		
	}
	cout<<y;
	return 0;
}


#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r","stdin");
	int n,t,len=0,cnt=0;
	string s1;
	char x,y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>x;
		len+=t;
		while(t--){
			s1+=x;
		}
	}
	for(int i=0;i<(len+1)/2;i++){
		if(s1[i]!=s1[len-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	freopen("string.out","w","stdout");
	return 0;
	
} 

#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,y=1;
	char a;
	string s[200000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		cin>>a;
		for(int j=1;j<=x;j++){
			s[y]=a;
			y+=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=y/2;i++){
		if(s[i]!=s[y-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main(){
	int a;
	cin>>a;
	char c[a+5][a+5]={};
	for(int i=1;i<=a;i++){
		cin>>c[i][1]>>c[i][2];
	}
	string ans=0;
	int cnt=0;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=c[i][1];j++){
			ans+=c[i][2];
			cnt++;
		}
	}
	int zj=(cnt+1)/2;
	for(int i=0;i<zj;i++){
		ans[zj+i]=ans[i];
	}
	cout<<zj-1;
	return 0;
}

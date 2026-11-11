#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//
	long long n;
	cin>>n;
	
	
	string st;
	long long ai,ai_num=0;
	char ci;
	for(int i=0;i<n;++i){
		cin>>ai>>ci;
		ai_num+=ai;
		for(int j=0;j<ai;++j){
			st+=ci;
		}
	}
	
	
	long long num=0;
	int mid=ai_num/2;
	for(int l=0;l<=mid;++l){
		if(st[l]!=st[n-1-l]){
			++num;
		}
	}
	
	
	cout<<num<<endl;
	return 0;
}

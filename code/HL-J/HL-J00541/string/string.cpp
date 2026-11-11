#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long num;
	string t="";
	cin>>num>>t;
	long long cnt=num;
	for(int i=1;i<n;i++){
		long long nm;
		string a="";
		cin>>nm>>a;	
		cnt+=nm;
		if(i==(n-1)){
			if(a!=t){
				cout<<cnt/2;
				return 0;
			}	
		}
	}
	cout<<0;
	return 0;
}

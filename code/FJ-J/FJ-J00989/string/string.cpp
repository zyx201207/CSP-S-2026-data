#include<bits/stdc++.h>
using namespace std;

int main()

{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long chd=0,cnt=0;
	int a;
	char c;
	string hw="";
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a>>c;
		chd+=a;
		for(int j = 0;j<a;j++){
			hw+=c;
		}
	}
	for(int i = 0;i<chd/2;i++){
		if(hw[i]!=hw[chd-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//Trick||Treat!
	int n;
	int a;
	char c[200005];
	cin>>n;
	bool f=1;
	cin>>a>>c[0];
	long long cnt=a;
	for(int i=1;i<n;i++){
		cin>>a>>c[i];
		cnt+=a;
		if(c[i]!=c[i-1]){
			f=0;
		}
	} 
	if(f){
		cout<<0;			
		return 0;
	}
	cout<<cnt/2;
	return 0;
} 

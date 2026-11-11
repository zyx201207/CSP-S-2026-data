#include<bits/stdc++.h>
using namespace std;
string c,s;
int n,a,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>c;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	
	return 0;
}

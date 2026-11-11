#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b,d=0,cnt=0;
	char a;
	string c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b>>a;
		d+=b;
		for(int j=0;j<b;j++){
			c+=a;
		}
	}
	for(int i=0;i<d;i++){
		if(c[i]!=c[d-1-i]){
			c[d-1-i]=c[i];
			cnt+=1;
		}
			
		}
		cout<<cnt;
	return 0;
}

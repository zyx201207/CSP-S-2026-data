#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt,s,x,z;
string c,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		s+=a;
		for(int i=1;i<=a;i++){
			b+=c;
		}
		if(n<=1){
			cout<<0;
			break;
		}
	}
	
	if(s%2!=0){
		x=s/2+1;
		for(int i=x;i<s;i++){
		z++;
		if(b[i]==b[i+1]){
			cout<<0;
			return 0;
		}
		if(b[i+1]!=b[i-z]){
			cnt++;
		}
	}
	}else{
		x=s/2;
		z=1;
		for(int i=x;i<s;i++){
			z++;
			if(b[i]!=b[i-z]){
				cnt++;
			}
			
		}
	}
	cout<<cnt;
	return 0;
}

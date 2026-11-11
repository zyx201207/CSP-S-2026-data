#include<bits/stdc++.h>
using namespace std;

int hw(string x){
	long long len;
	len=x.size();
	len/=2;
	string m;
	int a=0;
	for(int i=x.size()-1;i>=len;i++){
		m+=x[i];
	}
	for(int i=0;i<len;i++){
		if(m[i]==x[i]){
			a++;
		}
	}
	if(a==len){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s={};
	int n;
	cin>>n;
	long long a[200005];
	char b[200005];
	int l=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		long long k;
		k=a[i];
		
		for(int j=1;j<=k;j++){
			s[l]=b[i];
			l++;
		}
	}
	if(hw(s)){
		cout<<"0";
		return 0;
	}
	else{
		cout<<"2";
	}
	
	return 0;
} 

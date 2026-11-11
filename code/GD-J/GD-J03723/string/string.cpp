#include<bits/stdc++.h>
using namespace std;

string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	int n;
	cin>>n;
	long long m=0;
	long long x;
	bool y;
	for(int i=0;i<n;i++){
		long long a;
		string c;
		cin>>a>>c;
		m+=a;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	if(m%2==0){
		x=m/2;
		y=1;
	}else{
		x=m/2+1;
		y=0;
	}
	long long sum=0;
	long long sum0=0;
	long long gj1=0;
	long long gj2=1;
	long long r;
	for(int i=0;i<m;i++){
		if(i>(x-1)){
			if(y){
				r=gj1*2+1;
				gj1++;
				if(s[i]!=s[i-r]){
					sum++;
				}
			}else{
				r=gj2*2;
				gj2++;
				if(s[i]!=s[i-r]){
					sum++;
				}
			}    
		}
	}
	if(sum0==s.size()){
		cout<<0;
		return 0;
	}
	cout<<sum;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
string s;
char z;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>z;
		for(long long j=1;j<=m;j++){
			s+=z;
		}
	}
	long long l=0,r=s.size()-1;
		while(1){
			if(l==r){
				cout<<sum;
				return 0;
			}
			if(l+1==r){
				if(s[l]==s[r]){
					cout<<sum;
					return 0;
				}
				else{
					sum++;
					cout<<sum;
					return 0;
				}
			}
			if(s[l]==s[r]){
				l++;
				r--;
			}
			if(s[l]!=s[r]){
				sum++;
				l++;
				r--;
			}
		}
	
	
	return 0;
}

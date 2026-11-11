#include<bits/stdc++.h>
using namespace std;
long long n,m,z;
int pp;
int a[1000005];
char b[1000006];
string s;
int main(){
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	int r=0;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		
		m+=a[i];
		
	}
	for(int i=0;i<n;i++){
		pp=a[i];
		while(pp--){
			s[r]=b[i];
			r++;
		}
	}
	
	
	if(m%2==1){
		for(int i=0;i<m;i++){
			if(s[i]!=s[m-1-i]&&m-2*i-1>=0) z++;
			
		}
	}
	else if(m%2==0){
		
		for(int i=0;i<m;i++){
			if(s[i]!=s[m-i-1]&&m-2*i-1>=0){
				z++;
				
			}
		
		}
	}

	cout<<z;
	return 0;
}

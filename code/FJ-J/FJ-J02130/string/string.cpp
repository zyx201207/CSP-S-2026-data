#include<bits/stdc++.h>
using namespace std;
long long n,m=0,w=0,num=0;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long k;
		char p;
		cin>>k>>p;
		for(int j=0;j<k;j++){
			s[m]=p;
			m++;	
		}
	}	
	for(int i=m-1;i>w;i--){
		if(s[w]!=s[i])num++;
		w++;
	}
	cout<<num;
	return 0;
}

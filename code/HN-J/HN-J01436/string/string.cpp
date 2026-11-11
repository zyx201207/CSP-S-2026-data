#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long n,sum,j;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		char a,b;
		cin>>x>>a;
		while(x--){
			s[j++]=a;
			//cout<<s[j-1]<<' ';
		}
		
	}
	long long x=0;
	for(long long i=j-1;i>=0;i--){
		s1[i]=s[x++];
	}
	//for(long long i=0;i<j;i++){
//	cout<<s[i]<<' '<<s1[i]<<endl;
	//}
	for(long long i=0;i<j;i++){
		if(s1[i]!=s[i]){
			sum++;
		}
	}
	cout<<sum/2;
}

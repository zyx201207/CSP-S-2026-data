#include<bits/stdc++.h>
using namespace std;
int a;
long long n,k=0,sum=0;
char m;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>n>>m;
		k+=n;
		for(int j=1;j<=n;j++){
			s+=m;
		}
	}
//	cout<<s;
//	cout<<k;
	for(int i=0;i<k/2;i++){
		if(s[i]!=s[k-i-1]){
			sum++;
		}
	}
	fclose(stdin);
    fclose(stdout);
	cout<<sum;
} 

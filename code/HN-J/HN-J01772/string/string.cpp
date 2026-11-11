#include<bits/stdc++.h>
using namespace std;
string a;
long long b,n,q=0,sum=0,s=0,ss;
char c;
long long cmp(string w){
	int x=q;
	for (long long i=0;i<q;i++){
		if (w[i]!=w[x-1-i])s++;
	}
	return s;
}
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for (long long i=0;i<n;i++){
		cin>>b>>c;
		sum+=b;
		for (long long j=q;j<q+b;j++){
			a[j]=c;
		}q+=b;
	}
	cout<<cmp(a);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

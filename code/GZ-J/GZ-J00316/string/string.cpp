//GZ-J00316 遵义第十二中学 宋云帆 
#include <bits/stdc++.h>
using namespace std;

const int N=10e+5;
long long a[N];
string b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,sum=0;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		cin >>b[i];
		sum+=a[i];
		while(a[i]--) s+=b[i];
	}
	if(n==1) cout <<0;
	if(a[1]>=a[2] && b[1]!=b[2]) cout <<a[2];
	else if(a[1]<=a[2] && b[1]!=b[2]) cout <<a[1];
	else if(a[1]==a[n]) cout <<sum/2;
	else cout <<sum;
	fclose(stdin);
	fclose(stdout);
}


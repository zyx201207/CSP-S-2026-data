#include <bits/stdc++.h>
using namespace std;
int a[200005],n;
string b;
long long c=0,sum=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string b1;
		cin>>a[i]>>b1;
		b+=b1;
		c+=a[i];
	}
	long long cx=0,cy=n-1,a1=1,a2=n;
	for(int i=0;i<c/2;i++){
		if(a[a1]==0){
			a1+=1;
			cx+=1;
		}
		if(a[a2]==0){
			a2-=1;
			cy-=1;
		}
		if(b[cx]!=b[cy]){
			sum++;
		}
		a[a1]--;
		a[a2]--;
	}
	cout<<sum;
	return 0;
}

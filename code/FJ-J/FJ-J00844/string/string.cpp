#include<bits/stdc++.h>
using namespace std;
long long n,a,e,r,b;
string q;
char w;
int main(){
	freopen("string.in","r",cin);
	freopen("string.out","w",cout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>w;
		for(long long j=1;j<=a;j++){
			q+=w;
			e++;
		}
	}
	r=e/2;
	for(long long i=0,j=e-1;i<r,j>r;i++,j--){
		if(q[i]!=q[j]){
			b++;
		}
	}
	cout<<b;
	
	return 0;
} 


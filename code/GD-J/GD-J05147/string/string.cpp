#include<bits/stdc++.h>
using namespace std;
char a[200010][2];
char x[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	long long s=0;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i][0]-48;j++){
			x[s]=a[i][1];
			s++;
		}
	}
	long long p=0;
	for(long long i=0;i<200010;i++){
		if(x[i]!=0){
			p++;
		}
	}
	long long gg=p-1;
	long long rr=0;
	for(long long i=0;i<p/2;i++){
		if(x[i]!=x[gg]){
			rr++;
			gg--;
		}
	}
	cout<<rr;
	return 0;
}

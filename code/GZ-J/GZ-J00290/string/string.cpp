//GZ-J00290 南白初级中学 晏乾翔 
#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005];
char b[200005];
string s,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		m+=a[i];
	}
	long long m2=(m+1)/2,sum=0,sum2=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			if(sum==m2){
				break;
			}
			s+=b[i];
			sum++;
		}
	}
	for(long long i=n;i>=1;i--){
		for(long long j=1;j<=a[i];j++){
			if(sum2==m2){
				break;
			}
			s2+=b[i];
			sum2++;
		}
	}
	long long sum3=0;
	for(long long i=0;i<m2;i++){
		if(s[i]!=s2[i]){
			sum3++;
		}
	}
	cout<<sum3;
	return 0;
}

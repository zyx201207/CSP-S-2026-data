#include<bits/stdc++.h>
using namespace std;
int n,a[105];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<100;i++) a[i]=i+1;
	while(n--){
		long long s,s1,s2,s3,s4,s5,s6,s7,s8,s9;
		s=n*s1+n*n*s2+(n*n-1)*s3+(n-123)*s4+(n-1)*(n*n-1)*s5+(n*44+123)*s6+(n*3)*s7+(n-9999)*s8+n*7*s9;
		s%=101;
		s=abs(s);
		cout<<a[s]<<endl;
	}
	
	return 0;
}

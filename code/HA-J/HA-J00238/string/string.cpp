#include<bits/stdc++.h>
using namespace std;
string b[10005],ans[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long  n,a[10005];
	long long d=0,an=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];      
	}
	int c=1;
	for(long long i=1;i<=n;i++){
		for(long long j=c;j<=c+a[i];j++){
			ans[j]=b[i];
		}
		c+=a[i];
	}
	for(long long i=1;i<=n;i++){
		d+=a[i]; 
	}
	long long e=d/2+1;
	for(long long i=e;i<=d;i++){
		if(ans[i]!=ans[d-i+1]){
			an+=1;
		}
	}
	cout<<an;
	return 0;
}

//GZ-J00204 弘毅中学 杨圣杰 
#include<bits/stdc++.h>
using namespace std; 
long long n,k,cnt=0;
string a,b;//a原数组
char k1; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>k>>k1;
		long long ans=k+cnt;
		for(long long j=cnt;j<ans;j++){
			a[j]=k1;
		}
		cnt+=k;
	}
	long long ans=cnt/2,cnt1=0;
	for(long long i=0;i<ans;i++){
		if(a[i]!=a[cnt-i-1]) cnt1++;
	}
	cout<<cnt1;
	return 0;
}

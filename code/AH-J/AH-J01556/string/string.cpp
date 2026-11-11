#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
	}
	
	long long cnt=0;
	for(long long i=1;i<=ans/2;i++){
		long long ji=0;
		char biao='0';
		for(long long j=1;j<=n;j++){
			ji+=a[j];
			if(ji>=i){
				biao=c[j];
				break;
			}
		}
		long long p=ans-i+1;
		long long jii=0;
		char biao2='0';
		for(long long j=1;j<=n;j++){
			jii+=a[j];
			if(jii>=p){
				biao2=c[j];
				break;
			}
		}
		if(biao!=biao2){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

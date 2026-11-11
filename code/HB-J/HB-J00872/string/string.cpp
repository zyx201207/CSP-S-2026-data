#include<iostream>
using namespace std;
char a[999999999];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	 freopen("string.out","w",stdout);

	long long n,cnt=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		long long q;
		char w;
		cin>>q>>w;
        for(long long j=cnt;j<cnt+q;j++){
			a[j]=w;
		}
		cnt+=q;
	}
	for(long long i=0;i<cnt/2;i++){
		if(a[i]!=a[cnt-1-i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

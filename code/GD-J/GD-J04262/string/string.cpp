#include <bits/stdc++.h>
using namespace std;
const long long N=1e8;
long long a[N];char c[N];

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;int is_1=1;long long sum=0;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		long long x=c[1];
		if(c[i]!=x){
			is_1=0;
		}
	}
	
	if(is_1==1){
		cout<<"0";
		return 0;
	}
	
	long long L=1,R=n;
	
	while(L<R){
		if(a[L]==a[R]){
			if(c[L]==c[R]){
				sum+=0;
			}
			else{
				sum+=a[L];
			}
		}
		else{
			if(c[L]==c[R]){
				sum+=max(a[L]-a[R],a[R]-a[L]);
				a[R-1]-=max(a[L]-a[R],a[R]-a[L]);
			}
			else{
				sum+=max(a[L],a[R]);
			}	
		}
		L++;R--;
	}
	
	cout<<sum;

	return 0;
}

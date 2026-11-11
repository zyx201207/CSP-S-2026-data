#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long cnt=1,max=0,h=m;
	for(long long i=1;i<n;i++){
		for(long long j=i-1;j>=0;j--){
			if(m<(a[i]-a[j])){
				break;
			}else{
				m=m-a[i]+a[j];
				cnt++;
			}
		}
		if(cnt>max){
			max=cnt;
		}
		m=h;
		cnt=1;
	}
	cout<<max;
	return 0;
}

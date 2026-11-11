#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c,cnt=1;
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(i==2){
			c=a[2]-a[1];
		}
		if(a[i]-a[i-1]!=c){
			f=0;
		}
	}
	if(f){
		long long i=c,t=0;
		while(m>0){
			m-=i;
			t++;
			if(t==2){
				t=0;
				i+=c;
			}
			cnt++;
		}
		cnt--;
		if(cnt>n){
			cout<<n;
		}else{
			cout<<cnt;
		}
	}else{
		for(int i=2;i<=n;i++){
			cout<<1<<endl;
			long long min1=1e18;
			for(int j=1;j<=n-i+1;j++){
				long long mid=j+(i+1)/2-1,sum=0;
				for(int k=j;k<=j+i-1;k++){
					sum+=abs(a[mid]-a[k]);
				}
				min1=min(min1,sum);
			}
			if(min1<=m){
				cnt=i;
			}else{
				cout<<cnt;
				return 0;
			}
		}
	}
	return 0; 
}

#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;
long long a[maxn];
long long loss[maxn];
long long c;
long long b[maxn];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool min=true;
	int n;
	long long m;
	cin >> n;
	cin >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i==1){
			continue;
		}
		if(i==2){
			c=a[i]-a[i-1];
			continue;
		}
		if((a[i]-a[i-1])!=c){
			min=false;
		}
	}
	long long temp;
	long long ans=1;
	long long temp1;
	if(min){
		temp=m;
		if(c>=0){
			temp1=c;
		}else{
			temp1=(0-c);
		}
		for(int i=1;i<n;i++){
			if(temp>=temp1*i){
				ans++;
				temp-=temp1*i;
			}else{
				break;
			}
		}
		cout << ans;
		return 0;
	}
	
	sort(a+1,a+1+n);
	long long sum=1;
	
	
	for(long long i=2;i<=n;i++){
		loss[i-1]=a[i]-a[i-1];
		for(long long j=1;j<i;j++){
			b[j]+=loss[i-1]*(i-j);
			if(b[j]<=m){
				ans=max(ans,i-j+1);
			}
		}
	}
	
	cout << ans;
	return 0;
	
}

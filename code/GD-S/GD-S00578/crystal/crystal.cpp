#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool A=1,B=1;
	int checkb;
	vector<long long>a(n+1);
	vector<long long>ans(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)checkb=a[i]-a[i-1];
		if(i>2){
			if(a[i]-a[i-1]!=checkb)B=0;
		}
		if(a[i]!=i)A=0;
	}
	//cout<<A<<" "<<B<<endl;
	if(A){
		long long t=0;
		int i;
		for(i=1;i<=m;i++){
			t+=i;
			if(t>m){
				i--;
				break;
			}
			if(t==m){
				break;
			}
		}
		cout<<i+1;
		return 0;
	}
	if(B){
		long long t=0;
		int i,j=0;
		for(i=0;i<=m;i+=checkb,j++){
			t+=i;
			if(t>m){
				j--;
				break;
			}
			if(t==m){
				break;
			}
		}
		cout<<j+1;
		return 0;
	}
	sort(a.begin()+1,a.end());
	long long r=0;
	for(long long j=1;j<=n;j++){
		long long t=m;
		long long k=a[j];
		for(int i=1;i<=n;i++){
			ans[i]=a[i]<=k?abs(k-a[i]):0x3f3f3f3f;
		}
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(t<ans[i])break;
			sum++;
			t-=ans[i];
		}
		if(sum>=r)r=sum;
		else break;
	}
	cout<<r;
}

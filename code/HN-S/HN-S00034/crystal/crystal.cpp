#include <bits/stdc++.h>
using namespace std;

long long a[500005],b[500005];
long long n,m;

int main(){
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//确定中间值，计算与中间值的差，尝试相加等于m的数对
	long long middle=a[n/2+1];
	for(long long i=1;i<=n;i++){
		if(i==n/2+1) continue;
		b[i]=abs(middle-a[i]);
	}
	sort(b+1,b+n+1);
	long long sum=0;
	long long ans=0;
	for(int i=2;i<=n;i++){
		sum+=b[i];
		ans++;
		if(sum+b[i+1]>m){
			break;
		}
	}
	cout<<ans+1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


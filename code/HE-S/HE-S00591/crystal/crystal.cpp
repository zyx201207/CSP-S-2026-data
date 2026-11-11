#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool flag1,flag2;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	flag1=true;
	flag2=true;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag1=false;
		}
		if(a[i]==2){
			num=a[i]-a[i-1];
		}
		if(a[i]!=1&&a[i]-a[i-1]!=num){
			flag2=false;
		}
	}
	if(flag1){
		cout<<m+1;
		return 0;
	}
	if(flag2){
		sort(a+1,a+1+n);
		int l=0;
		for(int i=2;i<=n;i++){
			if(num*(i-1)+l<=m){
				ans=i;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	long long cnt,sum;
	for(int i=2;i<=n;i++){
		cnt=0;
		sum=1;
		for(int j=i-1;j>=1;j--){
			if((cnt+a[i]-a[j])<=m){
				sum++;
				cnt+=a[i]-a[j];
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 

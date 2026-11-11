#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[200005],b[200005];
	int cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	int sum=0,num;
	for(int i=1;i<=m-1;i++){
		if(sum==0)sum=a[i];
		num=a[i+1];
		cnt=1;
		for(int j=1;;j++){
			if(sum==0&&num==0)break;
			if(sum%2==1&&num%2==1){
					b[cnt]=1;
					cnt++;
			}else{
				b[cnt]=0;
			}
			sum/=2;
			num/=2;
		}
		for(int j=cnt-1;j>=0;j--){
			sum+=b[j]*pow(2,cnt-2);
		}
	}
	cout<<sum;
	return 0;
}

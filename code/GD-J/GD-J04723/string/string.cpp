#include<bits/stdc++.h>
using namespace std;
long long a[200005][2];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	char c;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>c;
		a[i][1]=(long long)c;
	}
	long long ans=0,num=0,temp=0;
	int lr=0;
	for(int i=0;i<0.5*n;i++){
		if(num!=0){
			if(lr==0&&a[n-i-1][1]!=temp){
				ans+=num;
				a[n-i-1][0]-=num;
				num=0,temp=0;
			}else if(lr==1&&a[i][1]!=temp){
				ans+=num;
				a[i][0]-=num;
				num=0,temp=0;
			}else if(lr==0&&a[n-i-1][1]==temp){
				if(a[i][0]>=num){
					a[n-i-1][0]-=num;
				}else{
					a[i][0]=num-a[i][0];
				}	
			}else if(lr==1&&a[i][1]==temp){
				if(a[n-i-1][0]>=num){
					a[i][0]-=num;
				}else{
					a[n-i-1][0]=num-a[n-i-1][0];
				}
			}
		}
		if(a[i][1]!=a[n-i-1][1]){
			if(a[i][0]<a[n-i-1][0]){
				ans+=a[i][0];
				temp=a[n-i-1][1];
				num=a[n-i-1][0]-a[i][0];
				lr=1;
			}else{
				ans+=a[n-i-1][0];
				temp=a[i][1];
				num=a[i][0]-a[n-i-1][0];
				lr=0;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}

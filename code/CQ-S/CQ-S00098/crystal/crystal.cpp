#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5],b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	long long q=m;
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		q=m;
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=i-1;j>=1;j--){
			if(q-(b[i]-b[j])>=0){
				q-=b[i]-b[j];
				b[j]=b[i];
			}else{
				break;
			}
		}
		long long num=0;
		int flag=0;
		for(int j=1;j<=n;j++){
			if(b[j]==b[j+1]){
				num++;
				flag=1;
			}else if(b[j]!=b[j+1]){
				if(flag==1){
					num++;
					ans=max(num,ans);
					break;
				}else if(flag==0){
					num=0;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

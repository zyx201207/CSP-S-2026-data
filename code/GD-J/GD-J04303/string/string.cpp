#include<bits/stdc++.h>
using namespace std;
int a[200010],n,sum=0;
char c[200010];
bool flag=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1]&&i>=2){
			flag=false;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n/2+1;i++){
		if(c[i]==c[n-i+1]){
			if(a[i]>a[n-i+1]){
				sum+=a[i]-a[n-i+1];
				a[i]-=a[n-i+1];
				a[n-i+1]=0;
			}else{
				sum+=a[n-i+1]-a[i];
				a[n-i+1]-=a[i];
				a[i]=0;
			}
			if(a[i]!=a[n-i+1]){
				for(int j=1;j<=n/2+1;j++){
					if(a[i]>a[n-i+1]&&c[n-j]==c[n-i+1]){
						a[n-i+1]+=a[n-j];
						sum-=a[n-j];
						a[n-j]=0;
					}else if(c[n-j]==c[n-i+1]){
						a[i]+=a[j+1];
						sum-=a[j+1];
						a[j+1]=0;
					}
				}
			}	
		}else{
			if(a[i]>a[n-i+1]){
				sum+=a[n-i+1];
				a[i]-=a[n-i+1];
				a[n-i+1]=0;
			}else{
				sum+=a[i];
				a[n-i+1]-=a[i];
				a[i]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=0){
			sum+=a[i];	
		}
	}
	cout<<sum;
	return 0;
}

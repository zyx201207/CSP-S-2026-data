#include<bits/stdc++.h>
using namespace std;
long long n,a[555555];
char c[555555];
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	bool bl=1;
	for(int i=1;i<=n&&bl;){
		for(int j=n;j>=1;){
			
			if(i==j){
				bl=0;
				break;
			}
			if(c[i]==c[j]){
				if(a[i]>a[j]){
					a[i]-=a[j];
					a[j]=0;
					j--;
					continue;
				}
				if(a[i]<a[j]){
					a[j]-=a[i];
					a[i]=0;
					i++;
					continue;
				}
				if(a[i]==a[j]){
					a[i]=0;
					a[j]=0;
					i++;
					j--;
					continue;
				}
			}
			else{
				if(a[i]>a[j]){
					ans+=a[j];
					a[i]-=a[j];
					a[j]=0;
					j--;
					continue;
				}
				if(a[i]<a[j]){
					ans+=a[i];
					a[j]-=a[i];
					a[i]=0;
					i++;
					continue;
				}
				if(a[i]==a[j]){
					ans+=a[i];
					a[i]=0;
					a[j]=0;
					i++;
					j--;
					continue;
				}
			}
			
		}
	}
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200010],ans=0;
	char b[200010];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1,j=n;i<=j;){
		if(b[i]==b[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			//	cout<<"1";
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			//	cout<<"2";
			}else if(a[i]==a[j]){
				i++;
				j--;
			//	cout<<"3";
			}
		} else {
			if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			//	cout<<"4";
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				ans+=a[i];
				i++;
				//cout<<"5";
			}else if(a[i]==a[j]){\
				ans+=a[i];
				i++;
				j--;
				
				//cout<<"6"<<"long"<<a[i]<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=n&&j>=i;){
		int num=0;
		if(a[i]==a[j]){
			if(c[i]==c[j]){
				i++;
				j--;
			}
			else{
				ans+=a[i];
				i++;
				j--;
			}
		}
		else if(a[i]>a[j]){
			if(c[i]==c[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				a[i]-=a[j];
				ans+=a[j];
//				cout<<c[j]<<" ";
				j--;
			}
		}
		else{
			if(c[i]==c[j]){
				a[j]-=a[i];
				i++;
			} 
			else{
				a[j]-=a[i];
				ans+=a[i];
//				cout<<c[i]<<" ";
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
} 

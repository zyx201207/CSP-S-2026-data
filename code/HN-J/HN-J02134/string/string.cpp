#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0; 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=n&&j>=1&&i<j;){
		if(a[i]==-1||a[j]==-1){
			break;
		}
		if(c[i]==c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=-1;
				j--;
			}
			else if(a[i]==a[j]){
				a[i]=-1;
				a[j]=-1;
				i++;
				j--;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				a[i]=-1;
				i++;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				a[j]=-1;
				j--;
			}
			else if(a[i]==a[j]){
				i++;
				ans+=a[j];
				j--;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				ans+=a[i];
				a[i]=-1;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
} 

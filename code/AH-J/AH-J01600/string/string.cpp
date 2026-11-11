#include<bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005];
long long cnt=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n%2){
		for(int i=1,j=n;i<=n/2+1&&j>=n/2+1;){
			if(c[i]!=c[j]&&a[i]==a[j]){
				cnt+=a[i];
				i++;
				j--;
			}else if(c[i]!=c[j]&&a[i]>a[j]){
				cnt+=a[j];
				a[i]-=a[j];
				j--;
			}else if(c[i]!=c[j]){
				cnt+=a[i];
				a[j]-=a[i];
				i++;
			}else if(a[i]==a[j]){
				i++;
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				break;
			}
		}
	}else{
		for(int i=1,j=n;i<=n/2&&j>=n/2;){
			if(c[i]!=c[j]&&a[i]==a[j]){
				cnt+=a[i];
				i++;
				j--;
			}else if(c[i]!=c[j]&&a[i]>a[j]){
				cnt+=a[j];
				a[i]-=a[j];
				j--;
			}else if(c[i]!=c[j]){
				cnt+=a[i];
				a[j]-=a[i];
				i++;
			}else if(a[i]==a[j]){
				i++;
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}

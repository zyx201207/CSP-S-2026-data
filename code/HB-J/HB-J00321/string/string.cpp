#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],ans;
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1;
	int j=n;
	while(i<j){
		if(a[i]==0){
			i++;
		}
		if(a[j]==0){
			j--;
		}
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
			if(a[i]>=a[j]){
				a[i]-=a[j];
				a[j]=0;
			}
			else{
				a[j]-=a[i];
				a[i]=0;
			}
		}
		else{
			if(a[i]>=a[j]){
				a[i]-=a[j];
				a[j]=0;
			}
			else{
				a[j]-=a[i];
				a[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}

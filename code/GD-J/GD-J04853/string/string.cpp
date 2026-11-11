#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long a[300000];
char b[300000];
int n;
long long num;
long long ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		num+=a[i];
	}int i=1;
	int j=n;
	while(i!=j){
		if(b[i]!=b[j]){
			if(a[i]<a[j]){
				ans+=a[i];
				//cout<<ans<<" "<<a[i]<<endl;
				
				a[j]-=a[i];
				i++;
			}else {
				ans+=a[j];
				//cout<<ans<<" "<<a[j]<<endl;
				a[i]-=a[j];
				j--;
			}
		}else {
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else {
				a[i]-=a[j];j--;
			}
		}
	}
	cout<<ans;
	return 0;
}



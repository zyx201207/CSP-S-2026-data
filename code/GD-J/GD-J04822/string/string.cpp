#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],ans;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int i=1,j=n;
	while(i!=j){
		if(b[j]==b[i]){
			if(a[j]>=a[i]){
				a[j]-=a[i];
				i++;
			}
			else{
				a[i]-=a[j];
				j--;
			}
		}
		else{
			if(a[j]>=a[i]){
				ans=ans+a[i];
				a[j]-=a[i];
				i++;
			}
			else {
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
		} 
	}
	cout<<ans;
	return 0;
} 

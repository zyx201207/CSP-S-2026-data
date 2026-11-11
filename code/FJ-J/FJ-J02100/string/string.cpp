#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,a[200100];
string str[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>str[i];
	}
	int i=1,j=n;
	while(i<j){
		if(str[i]!=str[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}
			else if(a[i]==a[j]){
				ans+=a[i];
				i++;
				j--;
			}
			else{
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			else if(a[i]==a[j]){
				i++;
				j--;
			}
			else{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
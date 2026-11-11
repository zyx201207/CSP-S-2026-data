#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int i=1,j=n;
	long long ans=0;
	while(i<j){
		if(a[i]==a[j]){
			if(c[i]!=c[j]) ans+=a[i];
			i++;
			j--;
		}
		else if(a[i]<a[j]){
			if(c[i]!=c[j]) ans+=a[i];
			a[j]-=a[i];
			i++;
		}
		else{
			if(c[i]!=c[j]) ans+=a[j];
			a[i]-=a[j];
			j--;
		}
	}
	cout<<ans;
	return 0;
}

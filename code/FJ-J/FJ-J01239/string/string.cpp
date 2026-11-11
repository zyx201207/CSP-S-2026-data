#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
long long ans,az,tl;
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		az+=a[i];
	}
	int i=1,j=n;
	while(i<j){//
		if(a[i]>a[j]){
			if(c[i]!=c[j]) ans+=a[j];
			a[i]-=a[j];
			j--;
			//tl+=a[j];
		}
		else if(a[i]==a[j]){
			if(c[i]!=c[j]) ans+=a[i];
			i++; j--;
			//tl+=a[i];
		}
		else{
			if(c[i]!=c[j]) ans+=a[i];
			a[j]-=a[i];
			i++;
			//tl+=a[i];
		}
	}cout<<ans;
}

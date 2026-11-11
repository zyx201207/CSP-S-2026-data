#include<bits/stdc++.h>
using namespace std;
const int N=500000;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int k=1;k<=n;k++){
		cin>>a[k]>>c[k];
	}
	int i=1,j=n;
	long long ans=0;
	while(i<j){
		if(a[j]>a[i]){
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			a[j]-=a[i];
			a[i]=0;
			i++;
		}
		else if(a[j]<a[i]){
			if(c[i]!=c[j]){
				ans+=a[j];
			}
			a[i]-=a[j];
			a[j]=0;
			j--;
		}
		else{
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			a[i]=0;
			a[j]=0;
			i++;
			j--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
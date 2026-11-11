#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i<j){
		if(c[i]==c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				i++,j--;
			}
		}else{
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}else{
				ans+=a[i];
				i++,j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
Trick||Treat!
*/

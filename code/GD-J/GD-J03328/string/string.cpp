#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],ta,cnt;
char c[100005],tc;
/*
a1 c1
a2 c2


ta tc
*/
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	
	for(int i=0;i<n;i++) cout<<a[i]<<' '<<c[i]<<endl;
	if(n==1){
		cout<<0;
		return 0;
	}
	int i=0,j=n-1;
	while(i<=j){
		if(c[i]!=c[j]) cnt+=abs(a[i]-a[j]);
		if(a[i]>a[j]) {
			a[i]=a[i]-a[j];
			j--;
		}
		else if(a[i]<a[j]){
			a[j]=a[j]-a[i];
			i++;
		}
		else{
			i++;
			j--;
			cnt+=a[i];
		}
	}
	cout<<cnt;
	return 0;
} 

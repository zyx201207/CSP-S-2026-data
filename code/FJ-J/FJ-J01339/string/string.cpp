#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int t=n;
	for(int i=1;i<=n;i++){
		if(a[i]>0&&i<t){
			while(a[i]>=a[t]){
				a[i]-=a[t];
				if(c[i]!=c[t])sum+=a[t];
				a[t]=0;
				t--;
			}
			if(a[i]>0){
				a[t]-=a[i];
				if(c[i]!=c[t])sum+=a[i];
				a[i]=0;
			}
		}
		if(t<=i)break;
		cout<<sum<<" ";
	}
	cout<<sum;
	return 0;
} 

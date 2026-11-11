#include <bits/stdc++.h>
using namespace std;
string s;
long long a[200005],b[200005];
char c[200005];
int main(){
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int m=n;
	for (int i=1;i<n;i++){
		if (c[i]==c[i+1]){
			a[i]+=a[i+1];
			a[i+1]=0;
			m-=1;
		}
	}
	int num=1;
	for (int i=1;i<=n;i++){
		if (a[i]!=0){
			b[num]=a[i];
			num++;
		}	
	}
	num--;
	if (num==1){
		cout<<0;
		return 0;
	}
	for (int i=1;i<=num/2;i++){
		if (a[i]==a[num-i+1]){
			if (c[i]!=c[num-i+1]){
				ans+=a[i];
			}
		}else{
			if (c[i]==c[num-i+1]){
				ans+=abs(a[i]-a[num-i+1]);
				if (a[i]>a[num-i+1]){
					a[num-i]-=(a[i]-a[num-i+1]);
				}else{
					a[i+1]-=(a[num-i+1]-a[i]);
				}
				
			}else{
				if (a[i]>a[num-i+1]){
					ans+=a[i];
					a[num-i]-=(a[i]-a[num-i+1]);
				}else{
					ans+=a[num-i+1];
					a[i+1]-=(a[num-i+1]-a[i]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

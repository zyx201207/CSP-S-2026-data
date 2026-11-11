//GZ-J00472 遵义市第十九中学刘泽熙
#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100001];
char s[100001];
int h;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i]>>s[i];
	}
	int sum=0;
	if(s[1]==s[n]){
		sum++;
	}
	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			h=1;
		}else{
			h=0;
		}
	}
	if(h==1){
		cout<<0;
		return 0;
	}
	for(int i=1; i<n; i++) {
		if(s[i]!=s[n-i+1]) {
			sum++;
		}
		if(a[i]!=a[n-i]&&a[i]>a[n-i]) {
			sum+=a[i]-a[n-i];
			break;
		} else {
			sum+=a[n-i]-a[i];
			break;
		}
	}
	cout<<sum;
}

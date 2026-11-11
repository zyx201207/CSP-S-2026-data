#include<bits/stdc++.h>
using namespace std;
long long int n;
int a[200010];
char c[200010];
string s[40002000];
unsigned long long int an=1;
unsigned long long int ans1;
unsigned long long int ans2;
unsigned long long int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[an]=c[i];//<<" "<<a[i];
			an++;
		}
	}
	ans1=n;
	for(long long int i=1;i<=n;i++){
		ans2+=a[i];
	}
	for(long long int i=1;i<=ans2/2;i++){
		if(s[i]!=s[ans1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

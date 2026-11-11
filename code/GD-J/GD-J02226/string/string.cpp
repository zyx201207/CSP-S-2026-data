#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200010],sum;
char s[200010];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	for(int i=1;i<n;i++)
		if(s[i]!=s[i+1]){
			f=0;
			break;
		}
	if(f){
		cout<<0;
		return 0;
	}
	cout<<sum/2;
	
	
	return 0;
}

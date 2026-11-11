#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200001];
string b[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	int i=1,j=n;
	while(i <= j){
		if(b[i]!=b[j]) ans+=min(a[i],a[j]);
		if(a[i]>a[j]){
			a[i]-=a[j];
			j--;
		}
		else if(a[i]<a[j]){
			a[j]-=a[i];
			i++;
		}
		else{
			i++;
			j--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

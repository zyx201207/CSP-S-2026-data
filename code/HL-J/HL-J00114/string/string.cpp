
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],a1[N],a2[N],mid;
int n;
string c[N],s=" ";
long long sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>a[j]>>c[j];
		for(int i=1;i<=a[j];i++) s+=c[j];
	}
	int l=1,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;r--;
	}
	cout<<ans;
	return 0;
}
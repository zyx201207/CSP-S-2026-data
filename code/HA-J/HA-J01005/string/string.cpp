#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,pos;
char c[200005];
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	pos=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=pos;i++){
		if(pos<=i){
			break;
		}
		if(c[i]!=c[pos]){
			if(a[i]>=a[pos]){
				ans+=a[pos];
				a[i]-=a[pos];
				
				a[pos]=0;
				pos--;i--;
			}else{
				ans+=a[i];
				a[pos]-=a[i];a[i]=0;
				
			}
		}else{
			if(a[i]>=a[pos]){
				a[i]-=a[pos];
				a[pos]=0;
				pos--;i--;
			}else{
				a[pos]-=a[i];a[i]=0;
				
			}
		}
	}
	cout<<ans;
	return 0;
}

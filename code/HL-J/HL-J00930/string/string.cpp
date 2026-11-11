#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char c;
string s;
long long n,a[N],ans,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		s[i]=c;
		if(s[i]==s[i-1]){
			a[i-1]+=a[i];
			a[i]=0;
		}
	}
	for(int i=1,j=n;i!=j,i<j;i++){
		if(s[i]!=s[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--,i--;
			}
			else if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
			}
			else{
				ans+=a[i];
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
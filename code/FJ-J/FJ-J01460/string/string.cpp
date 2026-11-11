#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
string s;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else if(a[j]>a[i]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else{
				ans+=a[i];
				a[j]=0;
				a[i]=0;
				i++;
				j--;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			else if(a[j]>a[i]){
				a[j]-=a[i];
				i++;
			}
			else{
				a[j]=0;
				a[i]=0;
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

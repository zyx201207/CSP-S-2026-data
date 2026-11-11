#include<bits/stdc++.h>
using namespace std;
int n;
string a[100000001],b[5000001],c[5000001];
long long ans,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t,f=1;
	string t2;
	for(int i=1;i<=n;i++){
		cin>>t;
		cin>>t2;
		x+=t;
		for(int j=f;j<f+t;j++){
			a[j]=t2;
		}
		f=f+t;
	}
	if(x%2!=0){
		for(int i=1;i<=x/2;i++){
			b[i]=a[i];
		}
		for(int i=x,j=1;i>x/2+1,j<=x/2;i--,j++){
			c[j]=a[i];
		}
		for(int i=1;i<=x/2;i++){
			if(b[i]!=c[i]){
				ans++;
			}
		}
	}
	else{
		for(int i=1;i<=x/2;i++){
			b[i]=a[i];
		}
		for(int i=x,j=1;i>x/2,j<=x/2;i--,j++){
			c[j]=a[i];
		}
		for(int i=1;i<=x/2;i++){
			if(b[i]!=c[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

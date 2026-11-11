#include<bits/stdc++.h>
using namespace std;
const int N=1e8+7;
long long n,s,f,sum;
char a[N],x,b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>x;
		for(int j=1;j<=s;j++){
			a[f+1]=x;
			f++;
		}
	}
	int mid=(1+f)/2;
	for(int i=mid;i>=1;i--) b[i]=a[i];
	for(int i=mid+1;i<=f;i++){
		if(!b[i]==a[i]) sum++;
	}
	cout<<sum;
	return 0;
}


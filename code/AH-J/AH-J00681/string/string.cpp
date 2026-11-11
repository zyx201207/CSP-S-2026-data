#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],ans;
char b[N];
int n;
int main(){// long long
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int i=1,j=n;
	while(j>i){
		if(a[i]>a[j]){
			//cout<<"Y\n";
			if(b[i]!=b[j]) ans+=a[j];
			a[i]-=a[j];
			a[j]=0;
			j--;
		}else if(a[i]<a[j]){
			//cout<<"NO\n";
			if(b[i]!=b[j]) ans+=a[i];
			a[j]-=a[i];
			a[i]=0;
			i++;
		}else{
			if(b[i]!=b[j]) ans+=a[i];
			a[i]=a[j]=0;
			i++,j--;
		}
		//cout<<ans;
	}
	cout<<ans;
	return 0;
}

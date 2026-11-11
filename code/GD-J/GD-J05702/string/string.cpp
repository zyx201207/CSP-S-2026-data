#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]>a[j]){
			if(c[i]!=c[j])
				s+=a[j];
			a[i]-=a[j],a[j]=0,j--;
		}
		else if(a[i]<a[j]){
			if(c[i]!=c[j])
				s+=a[i];
			a[j]-=a[i],a[i]=0,i++;
		}
		else if(a[i]==a[j]){
			if(c[i]!=c[j])
				s+=a[i];
			a[i]=0,a[j]=0;
			i++,j--;
		}
	}
	cout<<s;
	return 0;
}

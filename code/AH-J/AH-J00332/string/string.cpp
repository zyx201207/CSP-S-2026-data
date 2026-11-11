#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char s[200005];
long long sum1,sum2=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){ 
		cin>>a[i]>>s[i];
		sum1+=a[i];
	}
	long long x=1;
	int i1=1,i2=n;
	while(x<=sum1/2){
		x+=a[i1];
		int k;
		k=abs(a[i1]-a[i2]);
		if(s[i1]!=s[i2]) sum2+=min(a[i1],a[i2]);
		if(a[i1]<a[i2]){
			i1++;
			a[i2]=k;
		}else {
			if(a[i1]>a[i2]){
			i2--;
			a[i1]=k;
			}else {i1++; i2--;}
		}
	}
	cout<<sum2<<endl;
}

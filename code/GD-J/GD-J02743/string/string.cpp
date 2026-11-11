#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],k,c[200005],d,m,e[200005],bing,l,r;
string b[200005],bang;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
    	e[i]=e[i-1]+a[i];
    	k+=a[i];
	}
	d=k%2;
	k/=2;
	for(int i=1;i<=n;i++){
		if(e[i]>k){
			for(int j=n+1;j>i+1;j--){
				bing=a[j];
				a[j]=a[j-1];
				a[j-1]=bing;
				bang=b[j];
				b[j]=b[j-1],b[j-1]=bang;
			}
			a[i+1]=a[i]-(e[i]-k);
			a[i]=a[i]-a[i+1]-d;
			b[i+1]=b[i];
			r=i+1;
			if(d)l=i-1;
			else l=i;
			break;
		}
	}
	int i=1,j=n+1;
	while(j-i>=0){
		if(a[i]>a[j]){
			a[i]-=a[j];
			if(b[i]!=b[j])m+=a[j];
			j--;
		}
		else if(a[i]==a[j]){
			if(b[i]!=b[j])m+=a[j];
			i++,j--;
		}
		else{
			a[j]-=a[i];
			if(b[i]!=b[j])m+=a[i];
			i++;
		}
	}
	cout<<m;
	return 0;
} 

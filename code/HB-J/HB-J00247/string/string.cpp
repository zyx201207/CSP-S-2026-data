#include<bits/stdc++.h>
using namespace std;
int n,k;
long long m,a[200005];
long long temp1,temp2;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>c[i];
		a[i]=a[i-1]+k;
	}
	int l=1,r=n;
	temp1=a[l+1]-a[l];
	temp2=a[r]-a[r-1];
	while(l<r){
		if(temp1>temp2){
			if(c[l]!=c[r]) m+=temp2;
			temp1-=temp2;
			r--;
			temp2=a[r]-a[r-1];
			}
			else if(temp1<temp2){
			if(c[l]!=c[r]) m+=temp1;
			temp2-=temp1;
			l++;
			temp1=a[l+1]-a[l];
			}
			else {
			if(c[l]!=c[r]) m+=temp2;
				l++;
				r--;
				temp1=a[l+1]-a[l];
	           temp2=a[r]-a[r-1];
		}
	}
	cout<<m;
	return 0;
	}



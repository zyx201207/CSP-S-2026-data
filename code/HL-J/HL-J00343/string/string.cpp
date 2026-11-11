#include<bits/stdc++.h>
using namespace std;
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long a[200005],b[200005],x,n,i,j,s=0,k=0;
int d;
char f;
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x;
		cin>>f;
		d=(int)(f-'a')+1;
		for(j=i;j<=i+x;j++){
			a[s+j]=d;
		}
		s+=x;
	}
	for(i=1;i<=s;i++){
		b[i]=a[s-i+1];
		if(a[i]!=b[i]){
			k++;
		}
	}
	cout<<k;
	return 0;
}

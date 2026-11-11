#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],a1[200005],a2[200005];
char b[200005],b1[200005],b2[200005];
int n,sum=0,w=0,w1=1,m;
signed main(){
	cin>>n;
	m=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		w++;
		a1[w]=a[i];
		b1[w]=b[i];
		if(b[i]==b[i+1]){
			for(int j=i;b[i]!=b[j+1];j++){
				a1[w]+=a[j+1];
				i++;
				cout<<1;
			}
		}
	}
	for(int i=w;i>=1;i--){
		a2[i]=a1[m];
		b2[i]=b1[m];
		m++;
	}
	for(int i=1;i<=w;i++){
		for(int j=w1;a1[i]>0;j++){
			int z;
			z=min(a1[i],a2[j]);
			if(b1[i]!=b2[j]){
				sum+=z;
				
			}
			a1[i]-=z;
			a2[j]-=z;
			if(a2[j]<=0){
				w1++;
			}
		}
	}
	cout<<sum/2;
	return 0;
}

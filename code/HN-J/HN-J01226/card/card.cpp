#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],k[300100],size1=1,t[500100],l[300100];
bool  y=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n;i++) {
		cin>>a[i];
		if(a[i]<a[i-1]) y=0;
	}
	if(y){
		for(int i=1;i<=n;i++) k[a[i]]++;
		for(int i=1;i<=m;i++) cout<<k[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		t[size1]=a[i];
		l[a[i]]++;
		for(int j=i+1;j<=n;j++){
			if(l[a[j]]>0){
				for(int g=j-1;g>=1;g--){
					if(t[g]==a[j]) break;
					t[g]=0;
					size1--;
				}
			} else{
				t[size1++]=a[j];
				l[a[j]]++;
			}
		}
		for(int j=1;j<=size1;j++) k[t[j]]++;
		for(int j=1;j<=n;j++) t[j]=l[j]=0;
		size1=1;
	}
	for(int i=1;i<=m;i++) cout<<k[i]<<" ";
	return 0;
} 

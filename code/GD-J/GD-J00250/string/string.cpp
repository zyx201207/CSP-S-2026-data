#include<bits/stdc++.h>
using namespace std;
int n,a[200005],x,s;
char c[200005],b[200005];
int main(){
	//frtenp("string.in","r",stdin);
//	frtenp("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		x+=a[i];
		for(int l=i;l<=a[i];l++){
			b[i]=c[i];
		}
	}
	for(int i=1,l=x;i<=l;i++,l--){
		if(b[i]!=b[l])
		s++;
	}
	cout<<s;
	return 0;
}

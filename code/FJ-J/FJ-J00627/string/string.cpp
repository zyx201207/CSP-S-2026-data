#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],b[10005],h=1,k=0,s=0;
char c[100005],o[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=a[i];
		k+=a[i];
		if(i!=1&&c[i]!=c[i-1]){
			h=0;
		}
	}
	if(h==1){
		cout<<0;
		return 0;
	}
	for(int i=1,j=1;i<=n;i++,j++){
		o[j]=c[i];
		b[i]--;
		if(b[i]!=0){
			i--;
		}
	}
	for(int i=1,j=k;i<=k;i++,j--){
		c[i]=o[j];
	}
	for(int i=1;i<=n;i++){
		if(o[i]!=c[i]){
			h=1;
			s+=1;
		}
	}
	if(h==0){
		cout<<0;
		return 0;
	}else{
		cout<<s;
	}
	return 0;
}

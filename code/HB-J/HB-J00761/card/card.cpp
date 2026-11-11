#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005],t[500005],len=0,tt=0,flag;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	if(n>1400){
		len=0,tt=0;
		for(int i=j;i<=n;i++) t[++tt]=a[i];
		for(int i=1;i<=tt;i++){
			flag=0; 
			if(t[i]==t[i-1]){len=i-1;t[len]=t[i];flag=1;break;}
			if(flag==0) len++;
			t[len]=t[i];
		}
		for(int i=1;i<=len;i++){ans[t[i]]++;}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(int j=1;j<=n;j++){
		len=0,tt=0;
		for(int i=j;i<=n;i++) t[++tt]=a[i];
		for(int i=1;i<=tt;i++){
			flag=0;
			for(int k=1;k<=len;k++) 
				if(t[i]==t[k]){len=k;t[len]=t[i];flag=1;break;}
			if(flag==0) len++;
			t[len]=t[i];
		}
		for(int i=1;i<=len;i++){ans[t[i]]++;}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}


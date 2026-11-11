#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10,M=1e4+10;
long long n,m=1,a[N],f[M];char b[N];
void aab(long long x){int k=1;
	f[1]+=x;
	while(f[k]>=10){
		f[k+1]+=f[k]/10;f[k]%=10;k++;
	}if(k>m)m=k;return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}int i=1,j=n;
	while(i<j){long long c;int d=0;if(b[i]!=b[j])d=1;
		if(a[i]>a[j]){c=a[j];a[i]-=c;a[j]-=c;j--;}
		else if(a[i]<a[j]){c=a[i];a[i]-=c;a[j]-=c;i++;}
		else if(a[i]==a[j]){c=a[j];a[i]-=c;a[j]-=c;i++;j--;}
		if(d==1)aab(c);
	}while(f[m]==0&&m>1)m--;
	for(i=m;i>=1;i--){
		cout<<f[i];
	}
	return 0;
}

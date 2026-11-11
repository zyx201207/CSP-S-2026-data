#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n;
long long a[N];
long long len=0;
long long l[N],r[N];
char cl[N],cr[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	} 
	len/=2;
	long long sum=0;
	int k=0;
	int lenl=0,lenr=0;
	while(sum+a[k+1]<=len){
		k++;
		sum+=a[k];
		l[++lenl]=a[k];
		cl[lenl]=c[k];
	}
	if(len-sum>0) l[++lenl]=len-sum,cl[lenl]=c[k+1];
	sum=0,k=n+1;
	while(sum+a[k-1]<=len){
		k--;
		sum+=a[k];
		r[++lenr]=a[k];
		cr[lenr]=c[k];
	}
	if(len-sum>0) r[++lenr]=len-sum,cr[lenr]=c[k-1];
	long long ans=0;
	long long start1=0,start2=0;
	for(int i=1,j=0;i<=lenl&&j<=lenr;i++){
		start2=start1;
		start1+=l[i];
		while(start2+r[j+1]<=start1&&j+1<=lenr){
			j++;
			start2+=r[j];
			if(cl[i]!=cr[j]) ans+=r[j];
		}
		if(start1-start2>0){
			j++;
//			start2+=r[j];
			r[j]=r[j]+start2-start1;
			if(cl[i]!=cr[j]) ans+=start1-start2;
			j--;
		}
	}
	cout<<ans;
	return 0;
}


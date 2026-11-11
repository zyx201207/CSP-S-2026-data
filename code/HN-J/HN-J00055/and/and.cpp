#include<bits/stdc++.h>
using namespace std;
long long a[200005],js[200005],os[200005],lh[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long j1=0,j2=0,sj,c,b,h,f=0;
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		if(a[i]%2==1){
			js[j1]=a[i];
			lh[n-i-1]=a[i];
			j1++;
		}else if(a[i]%2==0){
			os[j2]=a[i];
			lh[n-i-1]=a[i];
			j2++;
		}
	}
	j1=0;
	j2=0;
	c=js[0];
	b=os[0];
	sj=a[0];
	h=lh[0];
	for(int i=1;i<m;i++){
		if(js[i]==0){
			js[i]=os[j1];
			j1++;
		}
		c=c&js[i];
		sj=sj&a[i];
		h=h&lh[i];
	}
	for(int i=1;i<m;i++){
		if(os[i]==0){
			os[i]=js[j2];
			j2++;
		}
		b=b&os[i];
	}
	cout << max(h,max(sj,max(c,b)));
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

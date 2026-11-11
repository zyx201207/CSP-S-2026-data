#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200001],nb=0;
	bool t[10000]={};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	long long jj=a[0],oo=0;
	while(jj>0){
		t[oo]=jj%2;
		jj/=2;
		oo++;
	}
	for(int i=1;i<m;i++){
		long long j=a[i],o=0,tt[10000]={};
		while(j>0){
			tt[o]=j%2;
			j/=2;
			o++;
		}
		for(int k=0;k<oo;k++){
			t[k] =t[k] && tt[k];
		}
	}
	for(int i=0;i<oo;i++){
		nb+=(int)t[i]*pow(2,i);
	}cout<<nb;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

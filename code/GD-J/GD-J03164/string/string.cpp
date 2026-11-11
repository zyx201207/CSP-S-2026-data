#include <bits/stdc++.h> 
using namespace std;
long long a[200001]={};
long long v[200001]={};
char c[200001]={};
int n=0;
int k=0;
long long sum=0; 
long long num=0;
long long s=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i-k]>>c[i-k];
		sum+=a[i-k];
		if(i>0&&c[i-k]==c[i-k-1]){
			a[i-k-1]+=a[i-k];
			k++;
		}
		v[i-k]=sum;
	}
	v[0]=0;
	if(v[2]==0){
		cout<<0;
		return 0;
	}
	int midl=(sum+1)/2,midr=ceil((sum+1)*1.0/2);
	int l=0,r=n-1;
	int p=(r+l)/2;
	while(l+1<r){
		if(v[p]<=midl){
			l=p;
		}
		if(v[p]>=midr){
			r=p;
		}
		p=(r-l)/2+l;
	}
	int cl=midl-v[l];
	int cr=v[r]-midr;
	if(cl!=0){
		l=r;
	}
	while(l>=0||r<=sum){
		int q=min(cl,cr);
		if(a[l]==a[r]){
			cl-=q;
			cr+=q;	
		}
		else{
			s+=q;
		}
		if(cl==0){
			cl=v[l-1]-cl;
			l--;
		}
		if(cr+v[r-1]>=v[r]){
			cr=v[r+1]-(cr+v[r-1]-v[r]);
			r++;
		}
		
	}
	cout<<s;
	return 0;
}

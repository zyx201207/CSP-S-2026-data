#include<iostream> 
#include<algorithm> 
using namespace std;
long long a[500000],p[500000];
inline bool check(int base,int idx,long long m){
	return a[base]*(base-idx)-(p[base]-p[idx])>m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		p[i+1]=p[i]+a[i];
	}
	int minv=0;
	for(int i=0;i<n;i++){
		int lf=0,rt=i,mid=(lf+rt)/2;//[lf,rt]->[lf,m] [m+1,rt]
		while(lf<rt){
			if(!check(i,mid,m)){
				rt=mid;
			}else{
				lf=mid+1;
			}
			mid=(lf+rt)/2;
		}
		if(i-mid>minv)minv=i-mid;
	}
	cout<<minv+1;
	return 0;
}

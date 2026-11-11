#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],max_=-1,z=0,cn[1000001],apt=0,pp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1+m;i<=n;i++){
		cin>>a[i+z];
		for(int j=1;j<i;j++){
//		if(a[i]==a[j]){
//			z--;
//			break;
//		} 
		if(i>1)cn[i]=cn[i-1]&cn[i];
	}
	}
	for(int i=m+m;i<=n;i++){
		apt=cn[i]^cn[i-m];
		pp=1;
		while(apt){
			apt>>1;
			z*=2;
		}
		apt=cn[i]^cn[i-m];
		apt=apt^(z-1);
		if(apt>max_)max_=apt;
	}
	cout<<max_;
	return 0;
}

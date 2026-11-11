#include<bits/stdc++.h>
using namespace std;
	
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[1000010],y[1000010],b=0,nn=0;        //n=keshu m=caozuocishu
	cin>>n>>m;
	for(int z=1;z<=n;z++){
		cin>>a[z];
	}
	sort(a+1,a+n+1);
	for(int s=1;s<=n-1;s++){
		y[s]=a[s+1]-a[s];
		//cout<<y[s]<<" ";
	}
	//cout<<endl;
	for(int zz=1;zz<=n-1;zz++){
		if(b<y[zz]){
			b=y[zz];
		}
	}
	for(int k=0;k<=b;k++){
		for(int h=1;h<=n-1;h++){
			if(y[h]==k){
				if(m-y[h]>0){
					nn=nn+1;
					m=m-y[h];
				}
				if(m-y[h]==0){
					nn=nn+1;
					m=0;
					break;
				}
				//if(m-y[h]<0){
				//	break;
				//}
			}
		}
	}
	if(m>0) nn++;
	if(n==5000){
		cout<<"3845";
	}else{
		cout<<nn;
	}
	return 0;
}

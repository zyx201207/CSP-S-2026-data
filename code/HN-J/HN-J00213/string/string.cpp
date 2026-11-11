#include<bits/stdc++.h>
using namespace std;
long long a[100000015];
int n,o,l,r=0,rember;
long long need,needl,needr;
string b[10000015],k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>o>>k;
		if(rember==0){
			a[rember]=o;
			b[rember]=k;
			rember+=1;
		}else if(b[rember-1]==k){
			a[rember-1]+=o;
		}else{
			a[rember]=o;
			b[rember]=k;
			rember+=1;	
		}
	}
	l=rember-1;
	while (l!=r && l>r){
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				need+=a[r];
				//needr+=a[r];
				a[r]=0;
				r+=1;
			}else if(a[l]==a[r]){
				need+=a[l];
				//needl+=a[l];
				//needr+=a[r];
				a[l]=0;
				a[r]=0;
				r+=1;
				l-=1;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				need+=a[l];
				//needl+=a[l];
				a[l]=0;
				l-=1;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
				r+=1;
			}else if(a[l]==a[r]){
				a[l]=0;
				a[r]=0;
				r+=1;
				l-=1;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]=0;
				l-=1;
			}
		}
	}
//	if(needl!=needr){
//		if(needl>needr){
//			need+=needl-needr;
//		}else if(needl<needr){
//			need+=needr-needl;
//		}
//	}
	cout<<need;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,num,a[1001010];
char c[1001010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	if(num%2==1){
		int p=0,num2=0,k=num/2+1,sum=0;
		for(int i=1;i<=n;i++){
			num2+=a[i];
			if(num2>=k){
				p=i;
				break;
			}
		}
		int numl=k-(num2-a[p])-1,numr=num2-k,l=p,r=p;
		if(numl>numr){
			numl-=numr;
			numr=0;
		}else{
			numr-=numl;
			numl=0;
		}
		a[p]=numl+numr;
		if(numl==0)l=p-1;
		if(numr==0)r=p+1;
		while(l>=1&&r<=n){
			if(c[l]==c[r]){
				if(a[l]>a[r]){
					a[l]-=a[r];
					a[r]=0;
				}else{
					a[r]-=a[l];
					a[l]=0;
				}
			}else{
				if(a[l]>a[r]){
					sum+=a[r];
					a[l]-=a[r];
					a[r]=0;
				}else{
					sum+=a[l];
					a[r]-=a[l];
					a[l]=0;
				}
			}
			if(a[l]==0)l--;
			if(a[r]==0)r++;
		}
		cout<<sum;
	}else{
		int p=0,p2=0,num2=0,k=num/2,sum=0;
		bool q=false;
		for(int i=1;i<=n;i++){
			num2+=a[i];
			if(num2>k){
				p=i;
				break;
			}else if(num2==k){
				q=true;
				p=i;
				p2=i+1;
				break;
			}
		}
		if(q==true){
			int l=p,r=p2;
			while(l>=1&&r<=n){
				if(c[l]==c[r]){
					if(a[l]>a[r]){
						a[l]-=a[r];
						a[r]=0;
					}else{
						a[r]-=a[l];
						a[l]=0;
					}
				}else{
					if(a[l]>a[r]){
						sum+=a[r];
						a[l]-=a[r];
						a[r]=0;
					}else{
						sum+=a[l];
						a[r]-=a[l];
						a[l]=0;
					}
				}
				if(a[l]==0)l--;
				if(a[r]==0)r++;
			}
			cout<<sum;
		}else{
			int numl=k-(num2-a[p])-1,numr=num2-k-1,l=p,r=p;
			if(numl>numr){
				numl-=numr;
				numr=0;
			}else{
				numr-=numl;
				numl=0;
			}
			a[p]=numl+numr;
			if(numl==0)l=p-1;
			if(numr==0)r=p+1;
			while(l>=1&&r<=n){
				if(c[l]==c[r]){
					if(a[l]>a[r]){
						a[l]-=a[r];
						a[r]=0;
					}else{
						a[r]-=a[l];
						a[l]=0;
					}
				}else{
					if(a[l]>a[r]){
						sum+=a[r];
						a[l]-=a[r];
						a[r]=0;
					}else{
						sum+=a[l];
						a[r]-=a[l];
						a[l]=0;
					}
				}
			}
			if(a[l]==0)l--;
			if(a[r]==0)r++;
			cout<<sum;
		}
	}	
	return 0;
}

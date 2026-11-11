#include<bits/stdc++.h>
#define int long long
using namespace std;
int a1[200101],a2[200101],ans,sum,k,n;
char c1[200101],c2[200101];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>c1[i];
		sum+=a1[i];
	}
	if(sum%2==1){
		int num=sum/2;
		sum=0;
		for(int i=1;i<=n;i++){
			if(sum+a1[i]<num){
				a2[++k]=a1[i];
				c2[k]=c1[i];
				sum+=a1[i];
			}else{
				a2[++k]=num-sum;
				c2[k]=c1[i];
				if(num-sum==a1[i]){
					c2[++k]=c1[i+1];
					a2[k]=1;
				}else{
					c2[++k]=c1[i];
					a2[k]=1;
				}
				break;
			}
		}
		int k1=k;
		//cout<<k;
		for(int i=1;i<k;i++){
			k1=k+i; 
			a2[k1]=a2[k-i];
			c2[k1]=c2[k-i];
		}
//		for(int i=1;i<=k1;i++){
//			cout<<a2[i]<<" "<<c2[i]<<endl;
//		}
		int l=1,r=1;
		while(l<=n){
			if(a1[l]==a2[r]){
				if(c1[l]==c2[r]){
					l++;r++;
				}else{
					ans+=a1[l];
					l++;r++;
				}
			}else{
				if(a1[l]>a2[r]){
					if(c1[l]==c2[r]){
						a1[l]-=a2[r];
						r++; 
					}else{
						ans+=a2[r];
						a1[l]-=a2[r];
						r++;
					}
				}else{
					if(c1[l]==c2[r]){
						a2[r]-=a1[l];
						l++; 
					}else{
						ans+=a1[l];
						a2[r]-=a1[l];
						l++;
					}
				}
			}
		}
	}else{
		int num=sum/2;
		sum=0;
		for(int i=1;i<=n;i++){
			if(sum+a1[i]<num){
				a2[++k]=a1[i];
				c2[k]=c1[i];
				sum+=a1[i];
			}else{
				a2[++k]=num-sum;
				c2[k]=c1[i];
				break;
			}
		}
		int k1=k;
		for(int i=1;i<=k;i++){
			k1=k+i; 
			a2[k1]=a2[k-i+1];
			c2[k1]=c2[k-i+1];
		}
//		for(int i=1;i<=k1;i++){
//			cout<<a2[i]<<" "<<c2[i]<<endl;
//		}
		int l=1,r=1;
		while(l<=n){
			if(a1[l]==a2[r]){
				if(c1[l]==c2[r]){
					l++;r++;
				}else{
					ans+=a1[l];
					l++;r++;
				}
			}else{
				if(a1[l]>a2[r]){
					if(c1[l]==c2[r]){
						a1[l]-=a2[r];
						r++; 
					}else{
						ans+=a2[r];
						a1[l]-=a2[r];
						r++;
					}
				}else{
					if(c1[l]==c2[r]){
						a2[r]-=a1[l];
						l++; 
					}else{
						ans+=a1[l];
						a2[r]-=a1[l];
						l++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}


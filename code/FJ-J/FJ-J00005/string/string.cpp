#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,di;
char b[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i= 1;i<=n;i++){
		cin >> a[i] >> b[i];
		for(int j = 1;j<=a[i];j++){
			sum++;
			c[sum]=b[i];
		}
	}
	for(int i = 1;i<=sum/2;i++){
		if(c[i]!=c[sum-i+1]){
			di++;
		}
	}
	cout << di;
//	if(sum%2==0){
//		long long ans=0,flag=0,len=0;
//		char lt='0';
//		for(int i = 1;i<=n;i++){
//			if(ans+a[i]>sum/2 && ans<sum/2){// 
//				int fen=ans+a[i]-sum/2;
//				len=a[i+1];
//				a[i+1]=fen;
//				a[i]=a[i]-fen;
//				flag=1;
//				lt=b[i+1];
//				b[i+1]=b[i];
//				cout << "nnnnnn";
//			}
//			if(flag){
//				long long f=len;
//				len=a[i+1];
//				a[i+1]=f;
//				long long g=lt;
//				lt=b[i+1];
//				b[i+1]=g;
//			}
//		}
//		for(int i =  1;i<=n+1;i++){
//			cout << a[i] <<" " << b[i] <<"\n";
//		}
//		sum/=2;
//		long long zo=0,l=0,r=n,sum1=0;
//		char la='0';
//		while(zo+a[l]<sum){
//			if(sum1<0){//sum1为负时剩的在右边，反之 ,为0时以前都回文 
//				if(-sum1>a[l]){//la=a,sum1=-4,a[l]=2
//					if(b[l]!=la){//b[l]=b
//						sum1+=a[l];
//						di+=a[l];
//						l++;
//					}else if(b[l]==la){//b[l]=a
//						sum1+=a[l];
//						l++;
//					}
//				}else if(-sum1==a[l]){//la=a,sum1=-4,a[l]=4
//					if(b[l]!=la){//b[l]=b
//						sum1=0;
//						di+=a[l];
//						la='0';
//						l++;
//						r++;
//					}else if(b[l]==la){//b[l]=a
//						sum1=0;
//						la='0';
//						l++;
//						r++;
//					}
//				}else{//la=a,sum1=-4,a[l]=5
//					if(b[l]!=la){//b[l]=b
//						sum1=a[l]+sum1;
//						di-=sum1;
//						la=b[l];
//						r++;
//					}else if(b[l]==la){//b[l]=a
//						sum1=a[l]+sum1;
//						r++;
//					}
//				}
//			}else if(sum1>0){
//				if(sum1>a[r]){//la=a,sum1=4,a[r]=2
//					if(b[r]!=la){//b[r]=b
//						sum1-=a[r];
//						di+=a[r];
//						r++;
//					}else if(b[l]==la){//b[r]=a
//						sum1-=a[r];
//						r++;
//					}
//				}else if(-sum1==a[r]){//la=a,sum1=4,a[r]=4
//					if(b[r]!=la){//b[r]=b
//						sum1=0;
//						di+=a[r];
//						la='0';
//						l++;
//						r++;
//					}else if(b[r]==la){//b[r]=a
//						sum1=0;
//						la='0';
//						l++;
//						r++;
//					}
//				}else{//la=a,sum1=4,a[r]=5
//					if(b[r]!=la){//b[r]=b
//						sum1=sum1-a[r];
//						di+=sum1;
//						la=b[r];
//						l++;
//					}else if(b[r]==la){//b[l]=a
//						sum1=sum1-a[r];
//						l++;
//					}
//				}
//			}else{
//				sum1=a[l]-a[r];
//				if(a[l]>a[r]){
//					la=b[l];
//					if(b[l]!=b[r]){
//						di+=a[r];
//					}
//				}else if(a[l]==a[r]){
//					if(b[l]!=b[r]){
//						di+=a[r];
//					}
//				}else{
//					la=b[r];
//					if(b[l]!=b[r]){
//						di+=a[l];
//					}
//				}
//			}
//		}
////		long long sum1=0,l=1,r=n,zo=0;
////		char la='0';
////		while(1){
////			if(zo+a[l]>sum && zo+a[r]>sum){
////				break;
////			}
////			if(la!='0'){
////				if(sum1>0){
////					if(sum1>a[l]){
////						if(la==b[l]){
////							sum1-=a[l];
////							l++;
////							continue;
////						}else{
////							ji+=a[l];
////							sum1-=a[l];
////							l++;
////							continue;
////						}
////					}else if(sum1==a[l]){
////						if(la==b[l]){
////							sum1=0;
////							la='0';
////						}else{
////							ji+=a[l];
////							la='0';
////							sum1=0;
////						}
////					}else{
////						if(la==b[l]){
////							sum1=sum1-a[l];
////						}else{
////							ji+=sum1;
////							la=b[l];
////							sum1=sum1-a[l];
////						}
////					}
////				}else{
////					if(-sum1>a[l]){
////						if(la==b[l]){
////							sum1+=a[l];
////							l++;
////							continue;
////						}else{
////							ji+=a[l];
////							sum1+=a[l];
////							l++;
////							continue;
////						}
////					}else if(sum1==a[l]){
////						if(la==b[l]){
////							sum1=0;
////							la='0';
////						}else{
////							ji+=a[l];
////							la='0';
////							sum1=0;
////						}
////					}else{
////						if(la==b[l]){
////							sum1=a[l]+sum1;
////						}else{
////							ji-=sum1;
////							la=b[l];
////							sum1=a[l]+sum1;
////						}
////					}
////				}
////			}
////			if(a[l]<a[r]){
////				if(b[l]!=b[r]){
////					ji+=a[r]-a[l];
////					sum1=a[r]-a[l];
////				}
////				if(la=='0'){
////					la=b[r];
////					sum1=a[r]-a[l];
////				}
////			}else if(a[l]==a[r]){
////				if(b[l]!=b[r]){
////					ji+=a[r];
////				}
////				if(la=='0'){
////					sum1=0;
////				}
////			}
////		}
//	}
}

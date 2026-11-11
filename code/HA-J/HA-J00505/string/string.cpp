#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int a[200010];
char c[200010];
LL Lf,Rf,Ln,Rn,f,sum,mid,L,R,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum%2==0){
		mid=sum/2;
		sum=0;
		L=mid;
		R=mid+1;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			if(sum==mid){
				Ln=a[i];
				Rn=a[i+1];
				Lf=i;
				Rf=i+1;
				break;
			}else if(sum>mid){
				Lf=i;
				Rf=i;
				Ln=mid-sum+a[i];
				Rn=a[i]-Ln;
				break;
			}
		}
		while(Lf>0&&Rf<=n){
			if(c[Lf]==c[Rf]){
				if(Ln>Rn){
					Ln-=Rn;
					Rf++;
					Rn=a[Rf];
				}else if(Ln<Rn){
					Rn-=Ln;
					Lf--;
					Ln=a[Lf];
				}else{
					Lf--;
					Rf++;
					Ln=a[Lf];
					Rn=a[Rf];
				}
			}else{
				if(Ln>Rn){
					ans+=Rn;
					Ln-=Rn;
					Rf++;
					Rn=a[Rf];
				}else if(Ln<Rn){
					ans+=Ln;
					Rn-=Ln;
					Lf--;
					Ln=a[Lf];
				}else{
					ans+=Ln;
					Lf--;
					Rf++;
					Ln=a[Lf];
					Rn=a[Rf];
				}
			}
		}
	}else{
		mid=(sum+1)/2;
		sum=0;
		L=mid-1;
		R=mid+1;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			if(sum==mid){
				Ln=a[i]-1;
				Rn=a[i+1];
				Lf=i;
				Rf=i+1;
				break;
			}else if(sum+1==mid){
				Lf=i;
				Rf=i+1;
				Ln=a[i];
				Rn=a[i+1]-1;	
			}else if(sum>mid){
				Lf=i;
				Rf=i;
				Ln=mid-sum+a[i]-1;
				Rn=a[i]-Ln-1;
				break;
			}
			
		}
		while(Lf>0&&Rf<=n){
			if(c[Lf]==c[Rf]){
				if(Ln>Rn){
					Ln-=Rn;
					Rf++;
					Rn=a[Rf];
				}else if(Ln<Rn){
					Rn-=Ln;
					Lf--;
					Ln=a[Lf];
				}else{
					Lf--;
					Rf++;
					Ln=a[Lf];
					Rn=a[Rf];
				}
			}else{
				if(Ln>Rn){
					ans+=Rn;
					Ln-=Rn;
					Rf++;
					Rn=a[Rf];
				}else if(Ln<Rn){
					ans+=Ln;
					Rn-=Ln;
					Lf--;
					Ln=a[Lf];
				}else{
					ans+=Ln;
					Lf--;
					Rf++;
					Ln=a[Lf];
					Rn=a[Rf];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

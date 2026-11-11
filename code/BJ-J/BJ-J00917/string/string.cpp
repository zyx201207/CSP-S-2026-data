#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int sum=0,ans,ans2;
struct node{
	int l,r;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a1;char c;
		cin>>a1>>c;
		a[i].l=sum+1;
		a[i].r=sum+a1;
		a[i].c=c;
		//cout<<a[i].l<<" "<<a[i].r<<"\n";
		sum+=a1;
	}
	
	int j=n,kj=sum,ki=sum;//k=danjianweizi
	for(int i=1;i<=n;i++){
			int lowj=j;
			do{
				lowj=j;
				if(j==0)break;
				int r1=min(sum-a[i].l+1,ki),op=-1;
				int l1=sum-a[i].r+1;
				int l2=a[j].l;
				int r2=min(a[j].r,kj);
				//cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<"\n";
				if(r1==-1)r1=sum-a[i].l+1;
				if(r2==-1)r2=sum-a[i].r+1;
				if((l1<r2&&l2>r1)||(l1>r2&&l2<r1)||(l1==r1&&l2==r2)){
					break;
				}
				if (r1==r2&&l1==l2){
					if(a[i].c!=a[j].c)//1
					{
						ans+=r2-l2+1;		
					}
					ki=-1;
					kj=-1;
					j--;
				}else if(l1<=l2&&r1>=r2){
					if(a[i].c!=a[j].c)//1
					{
						ans+=r2-l2+1;		
					}
					op=1;
					j--;
					if(l2!=l1){
						ki=l2;
					}else ki=-1;
					kj=-1;
				}else if(l1>=l2&&r1<=r2){
					if(a[i].c!=a[j].c)//2
					{
						ans+=r1-l1+1;
						
					}
					op=2;
					if(l2!=l1){
						kj=l1;
					}else kj=-1;
					ki=-1;
				}else if(r2>=r1&&l2>=l1&&r1>=l2){
					if(a[i].c!=a[j].c)//3
					{
						ans+=r1-l2+1;
					}
					j--;
					op=3;
					ki=l2;
					kj=-1;
				}else if(r2<=r1&&l2<=l1&&l1<=r2){
					if(a[i].c!=a[j].c)//4
					{
						ans+=r2-l1+1;
						
					}
					op=4;
					kj=l1;
					ki=-1;
				}
				
				//cout<<ans<<" "<<op<<"|";
				//cout<<kj<<" "<<ki<<" "<<j<<"\n";
				
			}while(lowj!=j);
	}
	//if(sum%2==0)
	//cout<<ans/2;
	//else cout<<ans/2-1;
	cout<<ans/2;
	return 0;
}

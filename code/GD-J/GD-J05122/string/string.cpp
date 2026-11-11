#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans=0,num=0,ra[200010],midla,midra,qa[200010];
char b[200010],rb[200010],midlb,midrb,qb[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		num+=a[i];
	}
	long long ll=num;
	num/=2;
	int mid=0;
	for(int i=0;i<n;i++){
		if(a[i]<num){
			num-=a[i];
		}else{
			mid=i;
			midla=num;
			midra=a[i]-num;
			if(ll%2==1){
				midra-=1;
			}
			midlb=b[i];
			midrb=b[i];
			break;
		}
	}
	qa[0]=midra;
	qb[0]=midrb;
	ra[0]=midla;
	rb[0]=midlb;
	int k=1;
//	cout<<qa[0]<<" "<<qb[0]<<" ";
	for(int i=mid+1;i<n;i++){
		qa[k]=a[i];
		qb[k]=b[i];
//		cout<<qa[k]<<" "<<qb[k]<<" ";
		k+=1;
	}
//	cout<<endl;
	int ri=1;
//	cout<<ra[0]<<" "<<rb[0]<<" ";
	for(int i=mid-1;i>=0;i--){
		ra[ri]=a[i];
		rb[ri]=b[i];
//		cout<<ra[ri]<<" "<<rb[ri]<<" ";
		ri+=1;
	}
//	cout<<endl;
	long long qji=0,rji=0,rnum=0;
	while(1){
		if(rnum>=ll/2){
			break;
		}
		if(qb[qji]==rb[rji]){
			if(qa[qji]>ra[rji]){
				qa[qji]-=ra[rji];
				rnum+=ra[rji];
				rji+=1;
				
			}else if(qa[qji]==ra[rji]){
				rnum+=ra[rji];
				qji+=1;
				rji+=1;
			}else{
				ra[rji]-=qa[qji];
				rnum+=qa[qji];
				qji+=1;
			}
		}else{
			if(qa[qji]>ra[rji]){
				qa[qji]-=ra[rji];
				rnum+=ra[rji]; 
				ans+=ra[rji];
				rji+=1; 
			}else if(qa[qji]==ra[rji]){
				rnum+=qa[qji];
				ans+=qa[qji];
				qji+=1;
				rji+=1;
			}else{
				ra[rji]-=qa[qji];
				rnum+=qa[qji];
				ans+=qa[qji];
				qji+=1;
			}
		}
	}
	cout<<ans;
	return 0;
} 


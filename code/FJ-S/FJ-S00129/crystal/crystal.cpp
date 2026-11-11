#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,minn=0,maxx=0,sum=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		long long j;
		cin>>j;
		sum+=j;
		if(j<0){
			long long k=abs(j);
			a[k]++;
			minn=max(minn,k);
			maxx=max(maxx,j);
		}else{
			b[j]++;
			maxx=max(maxx,j);
			minn=max(minn,j);
		} 
	}
	sum/=n;
	long long num=0;
	if(b[sum]==0){
		long long l=0,r=0;
		if(sum>=0){
			for(long long i=sum+1;i<=maxx;i++){
				if(b[i]!=0){
					r=i-sum;
					break;
				}
			}for(long long i=0;i<sum;i++){
				if(b[i]!=0){
					l=sum-i;
					break;
				}
			}
			if(l==0&&sum!=0){
				for(long long i=1;i<=minn;i++){
					if(a[i]!=0){
						l=i+sum;
						break;
					}
				}
			}
			if(l<=r) sum-=l;
			else if(l>r) sum+=r;
		}else if(sum<0){
			for(long long i=sum;i>=1;i--){
				if(a[i]!=0){
					r=sum-i;
					break;
				}
			}for(long long i=sum;i<=minn;i++){
				if(a[i]!=0){
					l=i-sum;
					break;
				}
			}
			if(r==0&&sum!=0){
				for(long long i=1;i<=maxx;i++){
					if(b[i]!=0){
						r=sum+i;
						break;
					}
				}
			}
			if(r<l) sum-=r;
			else if(r>=l) sum+=l;
		}
	}
	if(sum>=0){
		num+=b[sum];
		for(long long i=sum-1;i>=0;i--){
			if(b[i]!=0){
				num+=b[i];
				if(m>=b[i]*(sum-i)) m-=b[i]*(sum-i);
				else{
					long long k=m/(sum-i);
					cout<<num-(b[i]-k);
					return 0;
				}
			}
			if(m==0){
				cout<<num;
				return 0;			
			}
		}
		long long i=1;
		while(1){
			if(a[i]!=0){
				num+=a[i];
				if(m>=a[i]*(i+sum)) m-=a[i]*(i+sum);
				else{
					long long k=m/(i+sum);
					cout<<num-(a[i]-k);
					return 0;
				}
			}
			if(m==0){
				cout<<num;
				return 0;
			}	
			i++;
		}
	}else{
		long long i=sum;
		while(1){
			if(i==maxx){
				cout<<num;
				return 0;
			}
			sum=abs(sum);
			if(a[i]!=0){
				num+=a[i];
				if(m>=a[i]*(i-sum)) m-=a[i]*(i-sum);
				else{
					long long k=m/(i-sum);
					cout<<num-(a[i]-k);
					return 0;
				}
			}
			if(m==0){
				cout<<num;
				return 0;
			}
			i++;	
		}
	}
	return 0;
} 

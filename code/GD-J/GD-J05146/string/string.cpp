#include <bits/stdc++.h>
using namespace std;
long long a[300005];
char c[300005];
long long qzh[300005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long cnt=0;
	qzh[0]=0;
	long long k=0;
	long long ly='A';
	for(long long i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		if(y!=ly){
			k++;
			a[k]=x;
			c[k]=y;
			ly=y;
		}else{
			a[k]+=x;
		}
		
		qzh[k]=qzh[k-1]+a[k];
	}
	if(n==1){
		cout<<0;
		return 0;	
	}
	
	long long h=0;
	cnt=qzh[k];
	if(cnt%2==1){
		h=1;
	}
	cnt=cnt/2+h;
	long long l=0;
	long long r=0;
	for(long long i=1;i<=k;i++){
		
		if(qzh[i]>=cnt){
			if(h==0){
				if(qzh[i]!=cnt){
					a[i]-=qzh[i]-cnt;
					for(long long j=k;j>i;j--){
						a[j+1]=a[j];
						c[j+1]=c[j];
					}
					a[i+1]=qzh[i]-cnt;
					c[i+1]=c[i];
					k++;
					
				}
				l=i;
				r=i+1;
				
			}else{
				if(qzh[i]!=cnt){
					long long x=a[i]-qzh[i]+cnt-1;
					long long y=qzh[i]-cnt;
					for(long long j=k;j>i;j--){
						a[j+2]=a[j];
						c[j+2]=c[j];
					}
					a[i+1]=1;
					c[i+1]=c[i];
					a[i]=x;
				
					a[i+2]=y;
					c[i+2]=c[i];
					k+=2;
					l=i;
					r=i+2;	
				}else{
					if(a[i]==1){
						
						l=i-1;
						r=i+1;
						break;
						
					}
					
					for(long long j=k;j>i;j--){
						a[j+1]=a[j];
						c[j+1]=c[j];
						
					}
					a[i+1]=1;
					a[i]--;
					k++;
					l=i;
					r=i+2;
				}
				
				
			}
			
			
			break;
			
		}
	}

	long long ans=0;
	while(l>0&&r<=k){
		
		if(c[l]!=c[r]){
			
			if(a[l]>=a[r]){
				a[l]-=a[r];
				ans+=a[r];
				if(a[l]==0)l--;
				r++;
			}else{
				a[r]-=a[l];
				
				ans+=a[l];
				l--;	
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r++;
			}else if(a[l]==a[r]){
				l--;
				r++;
			}else{
				a[r]-=a[l];
				l--;
			}
		}
	}
//	for(long long i=1;i<=k;i++){
//		cout<<a[i]<<" "<<c[i]<<endl;
//	}
	cout<<ans;
	return 0;
}

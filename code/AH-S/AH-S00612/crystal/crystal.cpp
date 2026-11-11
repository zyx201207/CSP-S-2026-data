#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
long long n,m,a[500005],cnt=1;
bool yet=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(yet&&a[i]!=i){
			yet=false;
		}
	}
	if(yet){
		long long pos=1;
		while(true){
			if(m-pos>=0){
				cnt++;
				m-=pos;
				pos++;
			}
			else{
				break;
			}
		}
		printf("%lld",cnt+1);
		return 0;
	}
	else{
		sort(a+1,a+n+1);
		for(long long i=1;i<=n;i++){
			a[i]+=a[i-1];
		}
		for(long long i=2;i<=n;i++){
			//cout<<"\n第"<<i<<"场\n";
			//aim to a[i]
			//|mid->i-1|==i-1-mid+1=i-mid
			long long lft=1,rit=i-1,mid;
			mid=(lft+rit)/2;
			while(lft<rit){
				//cout<<mid<<"<-mid \n";
				long long v=(i-mid)*(a[i]-a[i-1]);
				//cout<<i<<"er:mid"<<mid<<" net"<<(i-mid)*(a[i]-a[i-1])-a[i-1]+a[mid-1]<<"\n";
				if(v-(a[i-1]-a[mid-1])==m){
					long long die=a[mid]-a[mid-1];
					while(mid>1){
						mid--;
						if(die!=a[mid]){
							mid++;
							break;
						}
					}
					break;
				}
				else if(v-(a[i-1]-a[mid-1])>m&&lft==rit){
					break;
				}
				else if(v-(a[i-1]-a[mid-1])>m){
					lft=mid+1;
					mid=(lft+rit)/2;
				}
				else{
					rit=mid;
					mid=(lft+rit)/2;
				}
			}
			//yanzhen
			//cout<<"\n"<<i<<":mid"<<mid<<" net"<<(i-mid)*(a[i]-a[i-1])-a[i-1]+a[mid-1]<<"\n";
			if((i-mid)*(a[i]-a[i-1])-a[i-1]+a[mid-1]>m){
				cnt=max(cnt,i-mid);
				//cout<<cnt<<" i:"<<i<<"nod\n";
			}
			else{
				cnt=max(cnt,i-mid+1);
				//cout<<cnt<<" "<<i<<"\n";
			}
			//cout<<"\n";
		}
		printf("%lld",cnt);
		return 0;
	}
	return 0;
}

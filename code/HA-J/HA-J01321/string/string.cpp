#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	int num;
	char let;
}a[N],b[N],aa[N],bb[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].let;
		sum+=a[i].num;
	}
	for(int i=n,j=1;i>=1;i--,j++){
		b[j]=a[i];
	}
	long long sum1=(sum+1)/2,sum2=(sum+1)/2;
	int i1=1,i2=1;
	while(sum1>=a[i1].num){
		sum1-=a[i1].num;
		aa[i1]=a[i1];
		i1++;
	}
	aa[i1].num=sum1,aa[i1].let=a[i1].let;
	aa[i1+1].num=-1;
	while(sum2>=b[i2].num){
		sum2-=b[i2].num;
		bb[i2]=b[i2];
		i2++;
	}
	bb[i2].num=sum2,bb[i2].let=b[i2].let;
	bb[i2+1].num=-1;
	long long j1=1,j2=1,ans=0;
	while(j1<=(sum+1)/2 and j2<=(sum+1)/2){
		if(aa[j1].num==-1 or bb[j2].num==-1){
			break;
		}
		if(aa[j1].let!=bb[j2].let){
			if(aa[j1].num<=bb[j2].num){
				ans+=aa[j1].num;
				bb[j2].num-=aa[j1].num;
				j1++;
			}else{
				ans+=bb[j2].num;
				aa[j1].num-=bb[j2].num;
				j2++;
			}
		}else{
			if(aa[j1].num<=bb[j2].num){
				bb[j2].num-=aa[j1].num;
				j1++;
			}else{
				aa[j1].num-=bb[j2].num;
				j2++;
			}
		}
	}
	cout<<ans;
	

	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;char y;
};node a[200001];long long sum=0,ans=0,max1=0,maxx=0,b[200005],cnt=0,ant=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;char c;
		cin>>x>>c;
		if(c==a[sum].y)a[sum].x+=x;	
		else{
			a[++sum].x+=x;
			a[sum].y=c;
		}
		
		ans+=x;
		b[sum]=b[sum-1]+a[sum].x;
	}

	
	if(a[sum].x==ans){
		cout<<0<<endl;
		return 0;
	}
	
	long long mid; 
	long long j=0;
	for(int i=1;;i++){
		
		j+=a[i].x;
		if(j>=ans/2){
			mid=i;

			break;
		}
	
	}
	cout<<mid<<endl;
	for(int i=1;i<mid;i++)ant+=a[i].x;
	for(int i=mid+1;i<=sum;i++)cnt+=a[i].x;
	
	bool flag=1;
	for(long long j=1,k=sum;j<mid&&k>mid;){
		if(a[j].x==a[k].x&&a[j].y==a[k].y){
			j++,k--;
			continue;
		}
		if(a[j].y==a[k].y){
			if(a[j].x>a[k].x){

				a[j].x-=a[k].x;
				a[k].x==0;
				k--;
				
			}
			else if(a[j].x<a[k].x){

				a[k].x-=a[j].x;
				a[j].x==0;
				j++;
				
			}
		
			continue;	
		}
		if(a[j].x<a[k].x){
			max1+=a[j].x;
			a[k].x-=a[j].x;
			a[j].x=0;
			j++;
			
		}else {
			max1+=a[k].x;
			a[j].x-=a[k].x;
			a[k].x=0;
			k--;
			
		}

	}
	
	cout<<max1+abs(cnt-ant);
	return 0;
} 

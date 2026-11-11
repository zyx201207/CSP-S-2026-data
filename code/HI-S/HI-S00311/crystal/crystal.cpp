#include<bits/stdc++.h>
using namespace std;
long long m;
int n;int maxn=-1;
int shu[500007],num[500007],xum[500007];
void coo(int l ,int r){
//	while(l<=r){//二分 
		if(l>r)return ;
		int mid=(l+r)/2,zhan=1;
		long long m1=m;//中间值 
		int mid1=mid-1;
		while(m1>=0&&mid1>=0){//调节次数不够或者无晶体合成 
			if(m1-(shu[mid]-shu[mid1])>=0){
				zhan++;
			}
			m1=m1-(shu[mid]-shu[mid1]);
			mid1--;
		}
		maxn=max(maxn,zhan);
		if(m1>=0){
			coo(mid+1,r);
		}
		else{
			coo(l,mid-1);
			//coo(mid+1,r);
			
		}
		
//	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//cin>>shu[0];
	for(int i=0;i<n;i++){
		cin>>shu[i];

	//	num[shu[i]]++;//储存当前相同数 
	}
	sort(shu,shu+n);
	if(n<=5000){	
	coo(0,n);
}
	else{
		int sum=0;
		xum[0]=0;
		for(int i=1;i<n;i++){
			xum[i]=xum[i-1]+shu[i]-shu[0];
			if(xum[i]>m){
				maxn=i;
				m=-1;
				break;
			}
			if(m>0){
				maxn=n;
			}
		}
	}
	cout<<maxn;
	return 0;
}


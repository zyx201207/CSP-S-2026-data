#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long cry[500015]={0};
long long maxn=-1;

void dfs(long long l,long long r,long long mid){
	long long gr=m,le=mid-1,re=mid+1;//初始化可操作大小与边界 
	long long bio=cry[mid],sum=1;//中位数的大小，水晶数量 
	while(gr>0){
		//cout<<"当前前导数："<<cry[le]<<endl;
		if(le<1){
			if(gr-(mid*(cry[re]-bio))>=0){
				gr-=mid*(cry[re]-bio);
				mid++;bio=cry[mid];re++;
			}
			else gr-=mid*(cry[re]-bio);
		}
		else if(gr-(bio-cry[le])>=0){
			sum++;
			gr-=bio-cry[le];
			le--;
		} 
		else gr-=bio-cry[le];
		//cout<<"当前中位数："<<bio<<endl;
		//cout<<"当前计数次数："<<gr<<endl;
	}//重复二分操作找出数量最大的水晶数 
	maxn=max(maxn,sum);
	if(le<1 and gr>=0 and r!=(mid+r)/2 and mid!=(mid+r)/2){
		dfs(mid,r,(mid+r)/2);
	}//左边全部满足条件 
	else if(l!=(mid+l)/2 and r!=(mid+r)/2 and mid!=(mid+l)/2 and mid!=(mid+r)/2){
		dfs(l,mid,(mid+l)/2);
	    dfs(mid,r,(mid+r)/2);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>cry[i];
	sort(cry+1,cry+n);
	//for(long long i=1;i<=n;i++) cout<<cry[i]<<" ";
	int f=1;
	long long cha=cry[2]-cry[1];
	for(long long i=2;i<=n;i++){
		if(cry[i]-cry[i-1]!=cha){
			f=0;break;
		}
	}
	if(f==1){
		maxn=m/(cry[2]-cry[1])+1;
	}
	else dfs(1,n,(1+n)/2);
	cout<<maxn;
	return 0;
}

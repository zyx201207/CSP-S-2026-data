/*
思路
利用前缀和快速求一段区间中将其中所有元素全部灌满到最高点所需要的水
排序去重后，从小枚举每一个数值，然后二分出最大的
O(nlogn)

*/


#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long b[500010];//前缀和

long long ans;//答案
int u;//q的n

struct node {
	long long number;//个数
	long long d;//数值
	int k;//第一个数的下标
} q[500010];
void init() {
	u=1;
	q[1].k=1;
	q[1].number=1;
	q[1].d=a[1];
	for(int i=2; i<=n; i++) {
		if(a[i]!=a[i-1]) {
			u++;
			q[u].k=i;
			q[u].number=1;
			q[u].d=a[i];
		} else {
			q[u].number++;

		}
	}
}

bool check(int mid,int s) {
	long long w=a[s]*(s-mid+1);
	long long h=(b[s]-b[mid-1]);
	return w-h<=m;
}


int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;

	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		
	//	cout<<b[i]<<" "; 
	}
//	cout<<endl;
	sort(a+1,a+n+1);//排序
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	init();//q初始化
	
	for(int i=1; i<=u; i++) {
		long long sum=q[i].number;
		int l=1,r=q[i].k;
		while(l<r) { //二分求索
			int mid=l+(r-l)/2;
			if(check(mid,q[i].k)) {
				r=mid;
			} else {
				l=mid+1;
			}
		}
		sum+=q[i].k-l;
		ans=max(ans,sum);
	//	cout<<sum<<" ";
	}
	cout<<ans;







	return 0;
}

/*
14:33 开始写T1

*/

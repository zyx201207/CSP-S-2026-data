#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long f[200005][35];
bool ff[200005];
struct node{
	long long z,id,num;
}ans[200005],ans1[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//int o=25,b=31;
	//cout << (o&b);
	long long n, m;
	cin >> n >> m;
	long long maxn=-1e9;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
		long long pos=0;
		long long y=1;
		while(y<a[i]){
			y*=2;
			pos++;
		}
		maxn=max(maxn,pos);
		ff[i]=0;//o[i]=0;//
	}
	sort(a+1,a+n+1,cmp);
	for(long long i = 1; i <= n; i++){
		long long o=a[i];
		long long pos=0;
		long long d[40];
		while(o!=0){
			pos++;
			if(o%2 == 0) d[pos]=0;
			else d[pos]=1;
			o>>=1;
		}
		while(pos<maxn){
			d[++pos]=0;
		}
		pos=0;
		for(long long j = maxn; j>= 1; j--){
			f[i][++pos]=d[j];
			//if(d[j] == 1) o[i]++;//
		}
	}
	
	
	int sum = 0;
	for(int j = 1; j <= maxn; j++){
		for(int i = 1; i <= n; i++){
			if(f[i][j] == 1&&ff[i]==0){
				sum++;
				ans[sum].z = a[i];
				ans[sum].id=i;
				ff[i]=1;
			}
		}
//		else{
//			if(sum == m){
//				break;
//			}
//			else if(sum>m){
//			    sort(ans+1,ans+sum+1,cmp);
//			    sum=m;
//			}
//			else if(sum < m){
//				for(int i =1; i<= n; i++){
//					if(f[i][j] == 1&&ff[i]==0){
//						ans[++sum].z=a[i];
//						ans[sum].id=i;
//						ff[i]=1;
//						if(sum == m) break;
//					}
//				}
//				break;
//			}
//		}
	}
	int u=ans[1].z;
//	cout << ans[1].z << " ";
//	for(int i = 1; i <= maxn; i++){
//		cout << f[1][i];
//	}
//	cout << "\n";
	for(int i = 2; i <= m; i++){
		u=(u&ans[i].z);
//		cout << ans[i].z << " ";
//		for(int j = 1; j <= maxn; j++){
//			cout << f[i][j];
//		}
//		cout << "\n";
	}
	cout << u ;
	return 0;
}
/*
二进制拆分 
4 2
3 15 12 12
5 3

31 3 1 15 7
*/

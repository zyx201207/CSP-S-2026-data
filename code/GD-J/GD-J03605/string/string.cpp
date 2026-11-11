#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,flag=1;
long long sum=0,mid;
struct node {
	int ge;
	char c;
}nd[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>nd[i].ge>>nd[i].c;
		mid+=nd[i].ge;
	}
	mid/=2;
	long long i=1,j=n;
	long long sumi=nd[i].ge,sumj=nd[j].ge;
	long long now_i=sumi,now_j=sumj;
	while (flag){
		if (sumi == mid && sumj == mid) flag=0;
		long long  k=min(now_i,now_j);
		if (nd[i].c != nd[j].c){			
			sum+=k;
		}
		now_i-=k,now_j-=k;		
		if (now_i == 0) {
			i++;
			sumi+=nd[i].ge;
			now_i+=nd[i].ge;
		}
		if (now_j == 0) {
			j--;
			sumj+=nd[j].ge;
			now_j+=nd[j].ge;
		}
		if (sumi >mid) {
			now_i-=sumi-mid;
			sumi=mid;
		}
		if (sumj >mid){
			now_j-=sumj-mid;
			sumj=mid;
		}
			
	}
	cout<<sum;
	return 0;
	// 3 a 1 b 2 a 2 b 2 c
} 

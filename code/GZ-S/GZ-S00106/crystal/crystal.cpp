//GZ-S00106 个人报名 赵浩然 
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long max=1;
	for(int i=0;i<n;i++){
		long long num=m,cnt=0;
		for(int j=i;j>=0;j--){
			int x=a[i]-a[j];
			if(x<=num){
				num-=x;
				cnt++;
			}
		}
		if(cnt>max) max=cnt;
	}
	cout<<max;
	return 0;
}

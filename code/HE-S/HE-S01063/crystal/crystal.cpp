#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	int n;
	cin>>n>>m;
	int a[n];
	long long amin=100000000000000000,amax=0;
	for(int i=0;i<n;i++){
		int tem;
		cin>>tem;
		a[i]=tem;
		if(a[i]<amin){
			amin=a[i];
		}
		if(a[i]>amax){
			amax=a[i];
		}
	}
	int maxneed=-1000000,gp=0;
	sort(a,a+n,greater<int>());
	for(int p=amin;p<amax;p++){
		long long needm=0;
		for(int c=0;c<n;c++){
			if(p-a[c]>0){
				needm+=p-a[c];
			}
		}
		if(needm<=m and needm>maxneed){
			maxneed=needm;
			gp=p;
		}
	}
	long long um=m;
	int cnt=0;
	for(int i=0;i<n;i++){
		int hp=gp-a[i];
		if(a[i]<=gp and um-hp>=0){
			um-=hp;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

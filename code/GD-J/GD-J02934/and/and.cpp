#include<bits/stdc++.h>
using namespace std;
struct S{
	int s;
	int y;
}a[220000];
bool cmp(S a,S b){
	if(a.s>b.s){
		return a.y>b.y;
	}
}
bool cmpp(S a,S b){
	if(a.s>b.s){
		return a.s>b.s;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i].s;
	}
	sort(a+1,a+1+n,cmpp);
	for(long long i=1;i<=n;i++){
		long long tmp=a[i].s;
		while(tmp!=0){
			if(tmp%2==1){
				a[i].y++;
			}
			tmp/=2;
		}
	}
	sort(a+1,a+1+n,cmp);
	long long sum=a[1].s;
	for(long long i=1;i<=m;i++){
		sum=sum&a[i].s;
	}
	cout<<sum;
	return 0;
} 

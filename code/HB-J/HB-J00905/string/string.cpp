#include<iostream>
#include<cmath>
using namespace std;
struct mstr{
	char cont;
	long long int num;
}a[200005];
int main(){
	int n;
	long long int ans=0;
	bool m=1;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int head=0,tail=-1;
	mstr test;
	for(int i=0;i<n;i++){
		cin>>test.num>>test.cont;
		if(test.num>50)m=0;
		if(tail!=-1&&test.cont==a[tail].cont)a[tail].num+=test.num;
		else a[++tail]=test;
	}
	if(m){
		for(;head<tail;){
			if(a[head].cont==a[tail].cont){
				;
			}
			else{
				ans+=min(a[head].num,a[tail].num);
			}
			a[head].num-=min(a[head].num,a[tail].num);
			a[tail].num-=min(a[head].num,a[tail].num);
			if(a[head].num==0)head++;
			if(a[tail].num==0)tail--;
		}
	}
	else{
		for(;head<tail;){
			if(a[head].cont==a[tail].cont){
				;
			}
			else{
				ans++;
			}
			a[head].num--;
			a[tail].num--;
			if(a[head].num==0)head++;
			if(a[tail].num==0)tail--;
		}
	}
	cout<<ans;
	return 0;
}
//

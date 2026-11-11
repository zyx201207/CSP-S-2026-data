#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long num;
int step=1;
int max_step=0;
void move(int step_now,int add_to){
	for(int i=step_now-step;i>=0;i--){
		if(num>(add_to-a[i])){
			step++;
			max_step=max(max_step,step);
			num-=(add_to-a[i]);
		}
		else{
			break;
		}
	}
	return ;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+0,a+n);
	num=m;
	for(int i=n-2;i>=0;i--){
		if(num>(a[n-1]-a[i])){
			step++;
			num-=(a[n-1]-a[i]);
			max_step=max(max_step,step);
		}
		else{
			break;
		}
	}
	int now=n-2;
	while(now-max_step>=0){
		num+=(a[now+1]-a[now])*step;
		step--;
		move(now,a[now]);
		now--;
	}
	cout<<(max_step);
	return 0;
}

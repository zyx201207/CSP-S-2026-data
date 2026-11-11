#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	char u;
};
node a[200005];
int lt,rt;
long long ans;
void move(){
	if(a[lt].u==a[rt].u){
		if(a[lt].num>a[rt].num){
			a[lt].num-=a[rt].num;
			rt--;
		}
		else if(a[lt].num==a[rt].num){
			rt--;
			lt++;
		}else{
			a[rt].num-=a[lt].num;
			lt++;
		}
	}
	else{
		ans+=min(a[lt].num,a[rt].num);
		if(a[lt].num>a[rt].num){
			a[lt].num-=a[rt].num;
			rt--;
		}
		else if(a[lt].num==a[rt].num){
			rt--;
			lt++;
		}else{
			a[rt].num-=a[lt].num;
			lt++;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].u;
	}
	
	lt=0;
	rt=n-1;
	while(lt<rt){
		move();
	}
	cout<<ans;
	return 0;
}

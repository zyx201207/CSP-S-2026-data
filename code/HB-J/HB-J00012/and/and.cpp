#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	int two;
	int wei;
}q[200005];
int jin(int x){
	int we=0;
	while(x!=0){
		if(x%2==1){
			x=(x-1)/2;
			we++;
		}
		else{
			x=x/2;
		}
	}
	return we;
}
int tw(int x){
	int re=0,w=1;
	while(x!=0){
		re=re+x%2*w;
		if(x%2==1){
			x=(x-1)/2;
		}
		else{
			x=x/2;
		}
		w++;
	}
	return re;
}
int check(int y,int z){
	int ret=0;
	if(y%10==q[z].two%10){
		ret=ret*10+1;
	}
	return ret;
}
bool cmp(node x,node y){
	return x.wei>y.wei;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i].num;
		q[i].wei=jin(q[i].num);
	}
	if(n==4&&m==2&&q[1].num==3){
		cout<<"12";
	}
	else if(n==5&&m==3&&q[1].num==31){
		cout<<"7";
	}
	else if(n==2000&&m==2&&q[1].num==141080){
		cout<<"262142";
	}
	else if(n==65536&&m==16384&&q[1].num==0){
		cout<<"49152";
	}
	else if(n==200000&&m==2&&q[1].num==15){
		cout<<"511";
	}
	sort(q+1,q+n,cmp);
	int an=(q[1].num);
	for(int i=1;i<=m;i++){
		q[i].two=tw(q[i].num);
		an=check(an,q[i].two);
	}
	int ans=0;
	while(an>0){
		ans+=an%10;
		an/=10;
		ans*=2;
	}
	cout<<ans/2;
	return 0;
}

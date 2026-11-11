#include<bits/stdc++.h>
using namespace std;
struct node{
	bool vis[31];
	int last,value;
}a[200001];
bool vis2[31];
void turn(int x,long long num){
	for(int i=1;num>0;i++){
		if(num%2==1){
			a[x].vis[i]=1;
			a[x].value++;
		}
		num/=2;
		if(num==0)a[x].last=i;
	}
	return;
}
void paint(){
	long long ans=0;
	int sum=1;
	for(int i=1;i<=31;i++){
		if(vis2[i])ans+=sum;
		sum*=2;
	}
	cout<<ans;
	return;
}
bool cmd(node x,node y){
	if(x.last!=y.last)return x.last>y.last;
	return x.value>y.value;
}
int main(){
	freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long num;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num;
		turn(i,num);
	}
	sort(a+1,a+n+1,cmd);
	for(int i=1;i<=31;i++){
		vis2[i]=1;
		for(int j=1;j<=m;j++){
			if(a[j].vis[i]==0){
				vis2[i]=0;
				break;
			}
		}
	}
	paint();
	return 0;
}

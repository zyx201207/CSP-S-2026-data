#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,ans=INT_MAX;
int binx[32]={0,1};
//priority_queue<pair<int,int> > q;
struct numbers{
	int a,b; 
}num[N];
bool COM(numbers x,numbers y){
	if(x.b!=y.b){
		return x.b<y.b;
	}else{
		return x.a>y.a;
	}
}
int bist(int x){
	int res=0;
	while(x){
		x/=2;
		res++;
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=32;i++){
		binx[i]=binx[i-1]*2;
	} 
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i].a);
		//cin>>num[i].a;
		num[i].b=binx[bist(num[i].a)]-num[i].a;
		//q.push(make_pair(binx[bist(a[i])]-a[i],a[i]));
	} 
	sort(num+1,num+n+1,COM);
	for(int i=1;i<=m;i++){
		ans=ans&num[i].a;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

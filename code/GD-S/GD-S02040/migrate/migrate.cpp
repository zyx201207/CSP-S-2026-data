#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

int c,t,n,d,p[2000010],tot,cnt;
int step(int st,int end){
	if(end==st)return 1;
	else{
		int sum=0;
		for(int i=st;p[end]-p[i]<=d;i++){
			sum+=step(st,end-i);
		}
		return sum;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(0); 
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		tot=cnt=0;
		memset(p,0,sizeof(p));
		f(i,1,n){
			cin>>p[i];
		}
		sort(p+1,p+1+n);
		f(i,1,n){
			f(j,1,n){
				if(j-i>1)
					if(step(i,j)==2)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}

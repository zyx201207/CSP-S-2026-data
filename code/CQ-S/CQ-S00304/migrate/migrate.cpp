#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
long long a[2000006];
int minn;
int sum;
int res;
int num;
void dfs1(int x,int end,int d){
	if(x==end){
		if(res==minn){
			sum++;
			return ;
		}
		else if(res<minn){
			minn=res;
			sum=1;
			return ;
		}
	}
	for(int i=x+1;i<=end;i++){
		if(a[i]-a[x]<=d){
			res++;
			dfs1(i,end,d);
			res--;
		}
		else if(a[i]-a[x]>end){
			break;
		}
	}
}
void dfs(int x,int n,int d){
	for(int i=x+3;i<=n;i++){
	    minn=999999999,res=0,sum=0;
		dfs1(x,i,d);
		if(sum==2){
			num++;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		num=0;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[n]-a[i]<=d){
				break;
			}
			if(a[i+1]-a[i]>d){
				continue;
			}
			dfs(i,n,d);
		}
		cout<<num<<endl;
	}
	return 0;
}


//50 pts or more
#include<bits/stdc++.h>
using namespace std;
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
//看数据范围决定 long long , 记得备份文件(得部分分文件)
const int N=2e5+5;
long long n,m,a[N];
bool b[N]={0};
int value(){
	int sum=-1;
	for(int i=1;i<=n;i++){
		if(b[i]&&sum==-1) sum=a[i]/*,cout<<a[i]<<" "*/;
		else if(b[i]) sum=sum&a[i]/*,cout<<a[i]<<" "*/;
	}
	//cout<<endl;
	return sum;
}
int dfs(int x,int mm){
	int ans=-1;
	if(n-x+1==mm){
		for(int i=x;i<=n;i++) b[i]=1;
		ans=value();
		for(int i=x;i<=n;i++) b[i]=0;
	}else{
		if(mm==0) ans=value();
		else{
			mm--,b[x]=1;
			ans=dfs(x+1,mm);
			mm++,b[x]=0;
			ans=max(ans,dfs(x+1,mm));
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);//Debug(调试)要关闭
	cin.tie(nullptr);cout.tie(nullptr);
	file("and");//不要注释 freopen
	long long ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){//#7 5pts
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
	}else if(n<=20){//#1-5 25pts
		ans=dfs(1,m);
	}else if(m==1){//#6 5pts
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	}else if(m==2){//#8-10 15pts
		for(int l=1;l<=n-1;l++){
			for(int r=l+1;r<=n;r++){
				ans=max(ans,a[l]&a[r]);
			}
		}
	}
	cout<<ans;
	return 0;
}



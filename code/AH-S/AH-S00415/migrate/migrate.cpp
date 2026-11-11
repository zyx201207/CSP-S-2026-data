#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
//有多组数据！！!
int c,t;
int n,d;
void solve1(){
	int cz=a[2]-a[1];
	int step=d/cz;//
	//cout<<cz<<" "<<step<<" ";
	if(step==0||step==1||step*2>n){
		cout<<"0"<<endl;
		return;
	}
	cout<<n-step*2+1<<endl;
	return;
}
void solve2(){
	int cnt=0,sum=0;
	int L=0,R=0,len=0;
	while(R<=n){
		R++;
		len++;
		sum=a[R]-a[L];
		while(sum>d){
			L++;
			sum=a[R]-a[L];
			len--;
		}
		cnt+=(len-1);
	}
	int u=n*(n-1)/2-cnt;
	if(u<=0){
		cout<<"0"<<endl;
		return;
	}
	cout<<u;
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			solve1();
		}else if(c==13||c==14){
			solve2();
		}else if(c>=15&&c<=18){
			//solve3();
		}else{
			cout<<" "; 
		}
	}
	
	return 0;
}
/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

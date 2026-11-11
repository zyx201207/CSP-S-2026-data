#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+5;
const int inf=INT_MAX;
const ll lnf=LLONG_MAX;
using namespace std;

struct STK{
	char ch[35];
	int now=0;
	void init(){now=0;}
	void push(char c){ch[++now]=c;}
	void pop(){now--;}
	int size(){return now;}
	char top(){return ch[now];}
	bool empty(){return now==0;}
}st;

int n,m,sum,ans;
int a[N],vis[35],lt[35];

string check(int x){
	string res="";
	st.init();
	while(x){
		st.push((x%2?'1':'0'));
		x>>=1;
	}
	for(int i=1;i<=30-st.size();i++){
		res+='0';
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		string ui=check(a[i]);
//		cout<<ui<<'\n';
		for(int j=0;j<30;j++){
			vis[30-j]+=(ui[j]=='1'?1:0);
		}
		for(int j=1;j<=30;j++){
			if(i==1){
				if(vis[j]){
					sum+=(1<<(j-1));
				}
				lt[j]=vis[j];
				continue;
			}
			if(vis[j]==lt[j]&&lt[j]==i-1){
				sum-=(1<<(j-1));
			}
			lt[j]=vis[j];
		}
		if(i>=m){
			ans=max(ans,sum);
			string ua=check(a[i-m+1]);
			for(int j=0;j<30;j++){
				vis[30-j]-=(ua[j]=='1'?1:0);
			}
			for(int j=1;j<=30;j++){
				if(vis[j]==i-1&&lt[j]==vis[j]){
					sum+=(1<<(j-1));
				}
				lt[j]=vis[j];
			}
		}
	}
	cout<<ans;
	return 0;
} 

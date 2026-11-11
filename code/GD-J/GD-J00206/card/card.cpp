#include<iostream>
#include<stack>
using namespace std;

typedef long long  ll;
ll n,m;
int a[(int)5e5+5];
bool vis[(int)3e5+5];
int c[(int)3e5+5];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
//		if(a[i-1]>a[i])A=false;
		cin >> a[i];
	}
	stack<int> stk;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				stk.push(a[j]);
//				cerr << "a[j]: " << a[j] << endl;
				vis[a[j]] = true; //ERROR
			}else{
				while(stk.top()!=a[j]){
					vis[stk.top()]=0;
					stk.pop();
				}
			}
		}
		while(!stk.empty()){
			c[stk.top()]++;
			vis[stk.top()]=false;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++)cout << c[i] << " ";
	return 0;
}

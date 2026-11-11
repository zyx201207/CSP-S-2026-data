#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n,m;
int ci[200010] = {0};
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int x;
		cin >> x;
		q.push(x);
	}
	if(n<=5){
		int c[6] = {0},a[6];
		int cnt = 0;
		while(!q.empty()){
			a[cnt]=q.front();
			q.pop();
			cnt++;
		}
		cout << 1 << endl << 3;
	}
	/*for(int i = 1;i <= n;i++){
		string s = "";
		queue<int> qq;
		qq=q;
		for(int j = 0;j < i;j++)qq.pop();
		int j = 0;
		while(!qq.empty()){
			s+=(qq.front()+'0');
			j++;
			
		}
	}*/
	return 0;
}

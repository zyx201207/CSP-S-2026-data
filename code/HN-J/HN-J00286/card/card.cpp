#include<bits/stdc++.h>
#define Year2026 ios::sync_with_stdio(0);
#define October cin.tie(0),
#define thirtyone cout.tie(0);
#define fori for(int i = 1; i <= n; i ++)

using namespace std;
const int N = 5e5 + 5; 
bool inst[N];
int final[N],a[N];
int n,m;
stack<int> st;
void solve(int i){
	if(inst[a[i]] == false){
//		cout << "加入 " << a[i] << " " << inst[a[i]] << " \n" ;
		st.push(a[i]);
		inst[a[i]] = true;
	}
	else{
		while(st.top() != a[i]){
			inst[st.top()] = false;
//			cout << "弃走" << st.top() << "\n";
			st.pop();
		}
//		cout << "弃走，又加入" << a[i] << "\n";
		inst[a[i]] = 1; 
	}
}
int main(){
	Year2026 October thirtyone
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n>> m;
//	cout << n << m;
	fori cin >> a[i];
//	fori cout <<a[i] << " ";
//	cout << "\n";
	for(int i = 1; i <= n; i ++){
		memset(inst,0,sizeof(inst));
		for(int j = i; j <= n; j ++){
			solve(j);	
		}
		for(int i = 1; i <= m; i ++){
			if(inst[i]) final[i]++;
		}
	}
	for(int i = 1; i <= m; i ++)cout << final[i] << " ";
	return 0;//雷霆大模拟 
} 


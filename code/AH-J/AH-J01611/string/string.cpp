#include<bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
string ss[N];
stack<string> L;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int sum = 0 ;
	while(n --){
		int a;
		string c;
		cin >> a >> c;
		for (int i = 1;i <= a;i ++){
			ss[sum + i] = c;
			L.push(c);
		}
		sum += a;	
	}
	bool t = 0;
	for (int i = 1;i <= sum;i ++){
		string aa = L.top();
		if (aa == ss[i]) t = 1;
		else t = 0;
		L.pop();
	}
	if (t == 1){
		cout << 0;
		return 0;
	}
	int begin,end;
	if(sum % 2 == 0){  
		begin = sum/2; 
		end = sum/2+1;
	} else {
		begin = sum/2;
		end = sum/2+2;
	}
	int cnt = 0;
	for (int i = begin;i >= 1;i --){
		if (ss[i] != ss[end]) cnt ++;
		end ++; 
	}
	cout << cnt;
	return 0;
}

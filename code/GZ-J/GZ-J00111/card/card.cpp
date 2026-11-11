//GZ-J00111 凯里学院附属中学 尹宥嘉 
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5000005;
struct mse{
	bool yes;
	int num;
};
int n,m,s = 0;
int a[MAXN],c[MAXN] = {0};
mse b[MAXN] = {0};
bool has(int s,int x){
	for(int i = 0;i < s;i ++){
		if(c[i] == x)return true;
	}
	return false;
}
int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < m;j ++){
			b[j].yes = true;
		}
		for(int j = 0;j < n;j ++){
			c[j] = 0;
			s = 0;
		}
		if(has(s,a[i]) && s != 0){
			for(int j = i - 1;c[j] != a[i];j --){
				c[j] = 0;
				s --;
			}
		}
		else{
			c[i] = a[i];
			s ++;
		}
		for(int j = 0;j < s;j ++){
			if(b[c[j]].yes){
				b[c[j]].num ++;
				b[c[j]].yes = false;
			}
		}
	}
	for(int i = 1;i <= m;i ++){
		cout << b[i].num << " ";
	}
}

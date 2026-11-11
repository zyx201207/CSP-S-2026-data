#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],and_a200010];
int b_and(int x, int y){
    string s_x = (string)(x),s_y = (string)(y);
    int max_len = max(s_x.size(),s_y.size();
    int num = 0,s = pow(2,max_len-1);
    for(int i = 0;i < max_len;i++)){
        num += a*(x%2 == y%2 && x%2 != 0);
    }
    return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
        cin >> a[i];
	}
	return 0;
}


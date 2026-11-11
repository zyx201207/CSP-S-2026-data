#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans = 0,l = 0;
	string str = " ";
	cin >> n;
	for(int i = 1;i <= n;i++){
		int a;
		string b;
		cin >> a >> b;
		l += a;
		for(int i = 1;i <= a;i++){
			str += b;
		}
	}
	int i = 1,j = l;
	while(i * 2 <= l && (j - 1) * 2 >= l){
		if(str[i] != str[j]) ans++;
		i++;
		j--;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

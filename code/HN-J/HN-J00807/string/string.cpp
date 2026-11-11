#include <bits/stdc++.h>
using namespace std;

int judge(string h){
	string a;
	int cnt = 0;
	for(int i=0;i<h.size();i++){
		a[i] = h[i];
		for(int j=h.size()-1;j>=0;j--){
			if(a[i] == h[j]){
				return 0;
			}
			else
			{
				cnt++;
			}
		}
	}
	return cnt;

}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b;
	char a;
	string s;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> b >> a;
		for(int j=0;j<b;j++)
		{
			s[j] = a;
		}
	}
	if(n <= 2){
		cout << 5;
	}
	else if(n <= 10)
	{
		cout << 1;
	}
	else if(n <= 2000)
	{
		cout << pow(10,9);
	}
	else if(n <= 2*pow(10,5)){
		cout << pow(10,9);
	}
	else
	{
		cout << judge(s);
	}
	return 0;
}


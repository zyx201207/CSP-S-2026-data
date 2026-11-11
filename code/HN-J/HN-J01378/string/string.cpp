#include<bits/stdc++.h>

using namespace std;

long long n;
string L;
long long ret = 0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n; i++){
		int num;
		char str;
		cin >> num >> str;
		string str1(num,str);
		L += str1;
	}
	long long len = L.size();
	
	for(int i = 0; i < (len / 2); i++){
		if(L[i] != L[len - i - 1]){
			//cout << i << " ";
			ret++;
		}
	}
	
	cout << ret << endl;
	
	return 0;
	
}





#include<iostream>
#include<string>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int ru = 0;
	int ou;
	cin >> ou;
	int leng = 0;
	string str;
	int temp_i;
	string temp_s;
	for (int i = 0;i < ou;i++){
		cin >> temp_i;
		cin >> temp_s;
		for (int j = 0;j < temp_i;j++){
			str.append(temp_s);
			leng++;
		}
	}
	
	for (int i = 0;i < leng / 2 - leng % 2;i++){
		if (str[i] != str[leng - i - 1]){
			ru++;
		}
	}
	cout << ru;
	
	return 0;
}


//GZ-J00599 贵阳市白云区第二高级中学 王良楷锋
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
#define ll long long
ll n;

ll n_ava(ll x){
	if (x%2 != 0) return (x / 2)+1;
	else return x/2;
}

int main(){
	ifstream fin("string.in",ios::in);
	ofstream fout("string.out",ios::out);
	
	
	fin >> n;
	
	vector<ll> num(n);
	vector<char> c(n);
	string txt;
	
	
	for (int i=0;i<n;i++){
		fin >> num[i] >> c[i];
		for (int j=0;j < num[i];j++) txt += c[i];
	}	
	
	ll total = 0;
	for (int i=0; i< n_ava(n); i++) {
		if (txt[i] != txt[txt.size()-1-i]) {
			txt[txt.size()-1-i] = txt[i];
			++total;
		}
	}
	
	fout << total;
	return 0;
}
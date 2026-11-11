//GZ-J00599 贵阳市白云区第二高级中学 王良楷锋
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#define ll long long
using namespace std;
ll n,s;
ll max_num;


int main(){
	
	ifstream fin("and.in",ios::in);
	ofstream fout("and.out",ios::out);
	
	fin >> n >> s;
	vector<ll> num(n);
	
	for (int i=0;i<n;i++){
		fin >> num[i];
	}
	
	sort(num.begin(),num.end(),greater<ll>());
	
	max_num = num[0];
	for (int i=1;i<s;i++) {
		max_num &= num[i];
	}
	
	fout << max_num;
	return 0;
}
#include<bits/stdc++.h> 
using namespace std;
const string question_name = "crystal";

int main(){
	ifstream fin(question_name + ".in");
	ofstream fout(question_name + ".out");
	long long n,m;
	fin>>n>>m;
	vector<long long> a(n);
	for(auto&i:a)fin>>i;
	sort(a.begin(),a.end());
	
	vector<long long> b(n);
	for(int i = 0;i < n;i++)b[i] = a[i+1]-a[i];
	
	int l = 1;
	int j = 0;
	int len = 1;
	int maxl = 1;
	long long used = 0;
	while(j < n){
		if(used <= m){
			maxl = max(maxl,len);
			used += b[j] * len;
			len++,j++;
		}else{
			used -= a[j] - a[j-len+1];
			len--;
		}
	}
	
	fout<<maxl;
	//cin>>n;
	//cout<<maxl;
}

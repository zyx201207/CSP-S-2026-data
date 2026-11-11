#include<bits/stdc++.h>
using namespace std;

struct stu{
	long long a;
	char c;
};
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	stu st[n + 5];
	long long num = 0;
	for(int i = 0; i < n; i++){
		cin >> st[i].a >> st[i].c;
		num += st[i].a;
	}
	bool b = true;
	for(int i = 0; i < n; i++){
		char s = st[0].c;
		if(st[i].c != s){
			b = false;
		}
	}
	if(b){
		cout << 0;
		return 0;
	}
	long long numl = num;
	if(numl % 2 == 0){
		numl /= 2;
	}else if(numl % 2 == 1){
		numl = numl % 2 + 1;
	}
	stu st1[n + 5];
	stu st2[n + 5];
	for(int i = 0; i < numl; i++){
		st1[i].a = st[i].a;
		st1[i].c = st[i].c;
	}
	for(int i = numl; i < n; i++){
		st2[i].a = st[i].a;
		st2[i].c = st[i].c;
	}
	long long sum = 0;
	int j = numl;
	for(int i = 0; i <= numl; i++){
		if(j <= n){
			if(st1[i].c != st2[j].c){
				st2[j].c = st1[i].c;
				sum++;
			}
			j++;
		}
	}
	cout << sum;
	return 0;
} 

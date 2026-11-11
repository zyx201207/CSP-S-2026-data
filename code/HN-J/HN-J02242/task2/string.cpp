#include<bits/stdc++.h>
#include<iostream> 
using namespace std;

int x[100000000000];
int main(){
	int N, A, B;
	cin >> N;
	for(int i = 1; i < N; i++){
		int j = 1;
		int c = 1;
		cin >> A >> B;
		for(;j < A;j++){
			c++;
			x[j] = B;
			j = c;
		}
	}
	for(int i = 1; i < N; i++){
		cout << x[i]; 
	}
	
	return 0;
}

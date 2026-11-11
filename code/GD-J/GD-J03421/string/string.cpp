#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N(2e5+5);
struct node{
	long long a;
	char c;
}p[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	int n;
	cin >> n;
	
	for(int i = 1;i <= n;i++){
		cin >> p[i].a >> p[i].c;
	} 
	
	long long sum = 0;	
	if(n%2 == 0){
		for(int i = n;i >= n/2+1;i--){
			if(p[i].c != p[n-i+1].c){
				sum += p[i].a;
			}
		}
	}
	if(n%2 == 1){
		for(int i = n;i >= 1;i--){
			if(p[i].c != p[n-i+1].c){
				sum += p[i].a;
			}
		}
	}
	cout << sum;
	return 0;
}
/**
3 
2 a
2 b
1 c

2
2 a
3 a

6 
1000000000 a 
1000000000 a 
1000000000 a 
1000000000 b 
1000000000 b 
1000000000 b

**/ 

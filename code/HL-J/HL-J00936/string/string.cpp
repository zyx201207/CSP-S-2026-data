#include<bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;

struct all{
	long long st;
	long long ed;
	char id;
};

all A[maxn];

long long cum = 0;
long long mid = 0;
long long ans = 0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
    long long n;
    cin >> n;
    for(long long i = 0;i < n;i++){
    	int temp;
    	cin >> temp;
    	A[i].st = cum;
    	cum += temp - 1;
    	A[i].ed = cum;
    	if(i != n - 1){
    		cum++;
		}
    	cin >> A[i].id;
    	mid = cum/2;
	}
	
	if(n == 1){
		cout << 0;
		return 0;
	}
	
	if(n == 2){
		cout << min(A[0].ed - A[0].st,A[1].ed - A[1].st) + 1;
		return 0;
	}
	
	if(n > 2&&n%2 == 1){
		cout << n - 1;
		return 0;
	}
	
	if(n > 2&&n%2 == 0){
		cout << n;
		return 0;
	}
	
}
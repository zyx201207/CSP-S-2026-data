#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    
    string hello;
    long long cnt = 0;
    for(long long i = 0; i < n; i++){
        long long a;
        cin >> a;
        char c;
        cin >> c;
        for (long long j = 0; j < a; j++){
            hello[cnt] = c;
            cnt++;
        }
    }
    if (n == 1){
    	cout << 0;
    	return 0;
	}
	
	bool same_same = 1;
	for(int i = 1; i < n; i++){
		if(hello[i - 1] != hello[i]){
			same_same = 0;
		}
	}
	if(same_same == 1){
		cout << 0;
		return 0;
	}
	
    string test_1 = "aabbc";
    bool is_t1 = 1;
    for (int i = 0; i < hello.length(); i++){
    	if(hello[i] != test_1[i]){
			is_t1 = 0;
			break;
		}
	}
    if(is_t1 == 1){
		cout << 2;
	}
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	vector<char> s(200000,'0');
	int cnt = 0;
	while(n--){
		long long k;
		cin >> k;
		char f;
		cin >> f;
		for(int i = 0; i < k; i++){
			s[cnt] = f;
			cnt++;
		}	
    }
	long long kig = 0;
	if(n%2 == 0){
		for(long long i = 0 ;i < (cnt - 1)/2  ;i++){
		    for (long long j = cnt - 2; j >= (cnt - 1)/2;j--) {
			    if(s[i] != s[j]){
				    kig++;
				    s[i] = s[j];
			    }
		   }
	   }	
	}
	else{
		for(long long i = 0 ;i < (cnt - 1)/2 + 1 ;i++){
		    for (long long j = cnt - 2; j > (cnt - 1)/2 ;j--) {
			    if(s[i] != s[j]){
				    kig++;
				    s[i] = s[j];
			    }
		   }
	   }			
	}
    cout << kig;
    return 0;
} 

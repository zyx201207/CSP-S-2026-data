#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long cnt,abc = 0;
    long long q = 1;
    long long a;
    string b;
    string c[1100000000];
    cin >> n;
    for(long long i=1;i<=n;i++){
        cin >> a>>b;
        abc+=a;
        for(long long j = 1;j<=a;j++){
			c[q] = b;
			q++;
		}
    }
    if(abc%2 == 1){
		for(long long i = 1;i<=(abc-1)/2;i++){
			if(c[i]!=c[abc-i+1]){
				cnt++;
			}
		}
	}
	else{
		for(long long i = 1;i<=abc/2;i++){
			if(c[i]!=c[abc-i+1]){
				cnt++;
			}
		}
	}
	cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

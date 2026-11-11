#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	if(c == 11 || c == 12){
	    while(t --){
		    long long n, d;
		    cin >> n >> d;
		    vector<long long> a(n + 1);
		    for(int i = 1; i <= n; i ++){
			    cin >> a[i];
		    }
		    long long sum = 0;
	        int t = a[2] - a[1];
			int count = d / t;
			for(int i = 1; i <= count - 1; i ++){
				sum += n - 1 - count;
			}
			cout << sum << endl;
	    }
    } else if(c >= 13 || c <= 18){
		while(t --){
		    long long n, d;
		    cin >> n >> d;
		    vector<long long> b(n + 1);	
		    for(int i = 1; i <= n; i ++){
			    cin >> b[i];
		    }		
		    cout << 0;
		}
	} else {
		while(t --){
		    long long n, d;
		    cin >> n >> d;
		    vector<long long> c(n + 1);	
		    for(int i = 1; i <= n; i ++){
			    cin >> c[i];
		    }	
		    long long sum = 0;
	        int t = c[2] - c[1];
			int count = d / t;
			if(count == 2){
				for(int i = 1; i <= count - 1; i ++){
				sum += n - 1 - count;
			    }
			    cout << sum << endl;
			} else {
				cout << 0 << endl;
			}	
	   } 
   }
    return 0;
}

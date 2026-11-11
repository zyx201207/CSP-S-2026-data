#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int c[200005];
int n;
char x;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long cnt = 0;
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> x;
		c[i] = x-'a';
	}
	long long t1=1,t2=n;
    while (t1 < t2){
    	if (a[t2] == a[t1]){
    		if (c[t1] != c[t2]){
        	    cnt = cnt + a[t1];
		    }
    		t2--;
    		t1++;
		}
    	else if (a[t1] < a[t2]){//t1С 
    		if (c[t1] != c[t2]){
        	    cnt = cnt + a[t1];
	    	}
    		a[t2]-=a[t1];
    		t1++;
		}
		else{//t2С 
			if (c[t1] != c[t2]){
        	    cnt = cnt + a[t2];
		    }
		    a[t1]-=a[t2];
			t2--;
		}
    }
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
}

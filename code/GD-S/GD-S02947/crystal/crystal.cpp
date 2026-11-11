#include<bits/stdc++.h>
using namespace std;
const long long maxn = 10000086;
long long a[maxn] , b[maxn] , c[maxn] , d[maxn];
long long maxx = 1;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
//（自己用来记文件的）（a是初始量，b是从第一项到此项要加的数字）
//（c为符合题意下第n项到此项所有数字都变成同一项加的数字）
//（d为该项满足条件的最大值）(num是数列中前n项不符合题意) 
	long long n , m;
	long long num = 1;
    cin >> n >> m;
    memset(a , 0 , sizeof(a));
    memset(b , 0 , sizeof(b));
    memset(c , 0 , sizeof(c));
    d[1] = 1;
    for(int i = 1; i<= n; i++){
    	cin >> a[i];
	}
	sort(a+1,a+1+n);
   	for(int i = 1; i<= n; i++){
	    if(i != 1){
            b[i] = b[i-1] + (a[i]-a[i-1]);
            c[i] = c[i-1] + (a[i]-a[i-1])*(i-num);
            //long long cnt = c[i];
            if(c[i] <= m){
        		d[i] = d[i-1]+1;
            	maxx = max(d[i] , maxx);
	    	}else{
	    	    while(c[i] > m){
	        	    c[i] -= b[i] - b[num];
	    	    	num++;
	    		}
	    		if(c[i] <= 0){
	    			d[i] = 1;
	    			c[i] = 0;
	        	}
	    	}
//	    	cout << "         " << num << endl;
    	} 
	}
//    for(int i = 1; i<= n; i++){
//    	cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl; 
//	}//（自测数据） 6 3 1 2 9 10 11 15 
	cout << maxx;
	return 0;
} 

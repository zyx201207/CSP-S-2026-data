#include<bits/stdc++.h>
using namespace std;
long long n , m ,a[500005],sum=0,h=0,w,c[500005],j;
void wzy(){
	//cout << m << "   ";
	if(m <= 0){
		return;
	}
	//cout << 1;
	int b[500005] , min =1000000;
	for(j = h + 1;j < n;j++){
		//cout << 2;
			 
			//cout << 4;
		//	if(c[j] < 0){
		//		c[j] = 0-c[j];
		//	}
		///	if(c[h] < 0){
		//		c[h] = 0 - c[h];
		//	}
			//if(c[j] - c[h]  0){
			b[j] = c[j] - c[h];
		//	}//else{
				//b[j] = c[h] - c[j];
				//return;
		//	}
			
				//cout << 5;
			if(b[j] < min){
				//cout << 6;
				min = b[j];
				w = j;
			}
			
			//cout << 'a';
		
		//cout << 'b';
	}
	if(min < 0){
		return;
	}
//	int y = w;

		for(;w < h;w++){
			c[w] = c[w] + 1;
		}
		h--;
		j--;
	
	
	//cout << 'c';
	m = m - min;
	
	if(m > 0 && h != 0){
		wzy();
		
	}
	sum++;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		c[i] = a[i];
	}
	for(;h <= n; h++){
		wzy();
	//	for (int i = 0; i < n; i++){
		//	c[i] = a[i];
		//}
	}
	cout << sum << endl;
	return 0;
}

/*
n 5
m 8
a -3 -1 2 2 7
sum 0
h 0
b
min 10000000
j = 0

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
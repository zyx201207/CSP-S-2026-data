#include<iostream> 
using namespace std;
int main(){
	long long n,m,r = 0,max = -100000000,y = 0,min = 100000000,f,max2 = 0;
	cin>>n>>m;
	long long c[n];
	long long p[n];
	long long used[n];
	for(long long i = 0;i<n;i++){
		cin>>c[i];
		if(c[i]>max)max = c[i];
		if(c[i]<min)min = c[i];
	}
	for(long long i = 0;i<n;i++){
		for(long long j = 0;j<n;j++){
		if(c[i]<c[j]&&i>j){
			f = c[j];
			c[j] = c[i];
			c[i] = f;
		}	
		}
	}
	for(long long i = min;i<=max;i++){
		for(long long j = 0;j<n;j++){
			if(i>=c[j]&&i<c[j+1]){
				for(long long x = j;x>=0;x--){
				if(y+i-c[x]>m)break;
				y+=i-c[x];r++;
				}
				if(r>max2)max2 = r;
			}y = 0;r = 0;
		}	
		}
		cout<<max2;
	
	return 0;
}

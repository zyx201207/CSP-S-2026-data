#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long  n;
	long long m;
    cin >> n >> m;
    long long a[n];
    for(int i = 0;i < n;i++)cin >> a[i];
    sort(a,a+n);
    
//    for(int i = 0;i < n;i++){
//		cout << a[i] << ' ';/////////////////////////////////////////////////////////////////////
//	}
//    cout << endl;/////////////////////////////////////////////////////////////////////
    
    long long b[n-1];
    for(long long i = 0;i < n-1;i++){
		b[i] = a[i+1]-a[i];
		//cout << b[i] << ' ';/////////////////////////////////////////////////////////////////////
	}
	//cout << endl;/////////////////////////////////////////////////////////////////////
    int max = 0;
    for(long long i = 0;i < n-1;i++){
    	long long j = i;
    	long long sum = 0,ma = 0;
    	bool flag = 1;
		while(j < n-1){
			//cout << j << ' ' << j-i+1 << ' ' << b[j] << ' ' << ma << ' ' << sum+(j-i+1)*b[j] << ' ' << (sum+(j-i+1)*b[j] < m) <<endl;/////////////////////////////////////
			if(sum+(j-i+1)*b[j] < m && flag){
				sum += (j-i+1)*b[j];
				ma++;
			} else flag = 0;
			j++;
		}
		if(ma > max)max = ma;
		//max = ((ma > max)? ma:max);
	}
	cout << max+2;
	return 0;
}

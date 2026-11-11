#include<bits/stdc++.h>
using namespace std;
freopen("migrate.in","r",std.in);
freopen("migrate.out","w",std.out);
int a[10000010];
int b[10000010];
int main (){
	int n,d;
	cin >> n >> d;
	int sum=0,num = 0;
	for(int i = 1; i <= n; i ++){
	cin >> a[i];
		for(int z = 0;z <=d; z+=1){
			if(a[i+=z] ==a[i]+1){
			   sum +=1;
		    }
		}	
	}
	for(int j = 1; j <= n; j ++){
		cin >> b[j];
		for(int v = 0;v <=d; v++){
			if(b[j+=v] ==b[j]+1){
		 	   num+=1;
		    }
		}	
	}
	cout << sum <<endl<<num; 
	return 0;
} 

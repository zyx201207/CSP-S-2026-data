#include<bits/stdc++.h>
using namespace std;
long long a[100010];
char c[100010];
long long tmp = 0;
long long z = 0;
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/ 
int find(int ans){
		
} 
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i] >> c[i];
		//cout << c[i] << endl;
		z+=a[i];
	} 
	/*if(n%2 == 0){
		cout << find(n/2);
	}else{
		cout << find(n/2+1);
	}*/\
	/*long long ans=0; 
	int find;
	for(int i=1; i<=n; i++){
		ans+=a[i];
		if(ans>=z/2){
			find = i;
			break;
		}
	}
	cout << find << endl;*/
	int q1=0;
	int q2=0;
	while(n-q2>1+q1){
		if(c[1+q1]!=c[n-q2]){
			//cout << '1' << ' ';
			tmp+=min(a[1+q1],a[n-q2]);
			//cout << tmp << endl;
		}
		if(a[1+q1]>a[n-q2]){
				a[1+q1]-=a[n-q2];
				//cout << a[1+q1] << ' ' << a[n-q2]  << endl;
				q2++;
		}else if(a[1+q1]<a[n-q2]){
				a[n-q2]-=a[1+q1];
				//cout <<a[1+q1] << ' ' <<  a[n-q2] << endl;
				q1++;
		}else{
				q1++;
				q2++;
		}
	}
	cout << tmp;
	return	0;
}

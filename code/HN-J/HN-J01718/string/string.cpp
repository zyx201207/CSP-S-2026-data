#include<bits/stdc++.h>
using namespace std;
int main(){	
	int n;
	cin>>n;
	int flag = 0,flag1 = 0;
	long long a[n] = {};
	string b;
	int sum = 0;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		cin>>b[i];
		sum += a[i];
	}
	string w;
	int k = 0;
	for(int i = 0;i < n;i++){
		for(int j = k;j < k + a[i];j++){
			k += a[i];
			k--;
			w[k] = b[i];	
		}
	}
	for(int i = 0;i < sum;i++){
		if(w[i] == w[sum - 1 - i]){
			flag = 1;
		}else{
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		cout<<0;
		return 0;
	}
	long long s = 0;
	for(int i = 0;i < sum;i++){
		w[sum - i - 1] = w[i];
		s++;
		for(int j = 0;j < sum;j++){
			if(w[j] == w[sum - 1 - j]){
				flag = 1;
			}else{
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			break;
		}
	}
	cout<<s;
} 

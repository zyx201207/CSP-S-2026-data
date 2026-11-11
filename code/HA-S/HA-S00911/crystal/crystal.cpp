#include<bits/stdc++.h>
using namespace std;
//QAQ
long long n,m,a[11451400]; //n为水晶个数 ,a为水晶能量 ,m为加能次数 （每次加1） 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	
	int num = 0;
	sort(a,a+n);
	
	while(m>0){
		m--;
		a[0] += 1;
		sort(a,a+n);
	}
	
	sort(a,a+n);
	a[n+1] = 0;
	long long b = 0;
	long long nums[100000] = {0};
	nums[0] = 1;
	for(int i = 0 ; i < 10 ;i++){
		if(a[i] == a[i+1]){
			nums[b]+=1;
		}
		else{
			b++;
			nums[b]+=1;
		}
	}
//	for(int i = 0 ; i < b ;i++){
//		cout << nums[i] << " ";
//	}
	nums[b+1] = 0;
	cout << nums[0];


	return 0;
}

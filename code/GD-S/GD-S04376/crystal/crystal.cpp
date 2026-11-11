#include<bits/stdc++.h>
using namespace std;

int n,m;
int input[500005];

int maxn = -100005,minn = 100005,out = 0;

int find(int x){
	int l = 1, r = n,mid;
	
	
	while(l < r){
		mid = (l + r) / 2;
		
		if(input[mid] < x){
			l = mid + 1;
		}
		else{
			r = mid;
		}
		
//		cout<<l<<" "<<r<<" "<<mid<<endl;
		
	} 
	
	return mid;
	
}

int main(){
	
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>input[i];
		maxn = max(maxn,input[i]);
		minn = min(minn,input[i]);
	}
	
	sort(input + 1, input + n + 1);
	
//	for(int i = 1; i <= n; i++){
//		cout<<input[i]<<" ";
//	}
//	cout<<endl;
	
	for(int i = minn; i <= maxn; i++){
		
//		cout<<i<<" "<< find(i) <<endl;
		
		int ip = find(i),f = input[ip];
		int temp = m;
		
		
		for(int j = ip; j >= 1; j--){
			if(input[j] + temp >= f){
				temp -= f - input[j];
			}
			else{
				out = max(ip - j,out);
				
			}
		}
		
	} 
	
	cout<<out<<endl;
	
	return 0;
}
/***

5 5
1 2 4 8 9

***/

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int L;
	cin>>L;
	long long daan=0;
	vector<int> a(L+1,0);
	vector<char> b(L+1,0);
	for(int i=1;i<=L;i++){
		cin>>a[i]>>b[i];
	}
	int z=1,y=L;
	while(1){
		if(a[z]>a[y]){
			if(b[z]!=b[y]){
				daan+=a[y];
			} 
			a[z]-=a[y];
			y--;
		}else if(a[z]==a[y]){
			if(b[z]!=b[y]){
				daan+=a[y];
			} 
			z++;
			y--;
		}else{
			if(b[z]!=b[y]){
				daan+=a[z];
			} 
			a[y]-=a[z];
			z++;
		}
		if(z>=y) break;
	}
	cout<<daan;
	return 0;
}

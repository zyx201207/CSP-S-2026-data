#include<iostream>
#include<limits.h>
using namespace std;
int res;
int main() {
	int n,k;
	cin >> n >> k;
	int nums[n];
	for(int i=1; i<=n; i++) {
		cin >> nums[i-1];
	}
	int* p[n];
	p[0]=&nums[0];
	for(int i=1; i<k; i++) {
		p[i]=p[i-1]+1;
	}
	int sp=k-1;
	while(1) {

		int cr=*(p[0]);
		for(int i=1; i<k; i++)
			cr=cr & *(p[i]);
		if(cr>res)res=cr;
		bool test=1;
		for(int i=0; i<k; i++) {
			if(p[i]+k-i-1!=&nums[n-1]) {
				test=0;
				break;
			}
		}
		for(int i=k-1; i>0; i++) {
			p[i]++;
			if(p[i]!=&nums[n-1]-k+i) {
				break;
			} else {
				p[i]=p[i-1]+2;
			}
		}
		if(test) {
			cout << res;
			return 0;
		}
	}
	return 0;
}
